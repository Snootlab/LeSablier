#include "LeSablier.h"

#include <Wire.h>

#define LESABLIER_I2C_ADDRESS 104

#ifdef LESABLIER_DAY_NAMES
static const char* dayNames[7] = LESABLIER_DAY_NAMES;
#endif
#ifdef LESABLIER_MONTH_NAMES
static const char* monthNames[12] = LESABLIER_MONTH_NAMES;
#endif

LeSablier_ LeSablier;

void LeSablier_::begin() {
    update();
}

void LeSablier_::end() {
}

void LeSablier_::update() {
    _lastUpdate = millis();
    Wire.beginTransmission(LESABLIER_I2C_ADDRESS);
    Wire.write(0x00); // start at register 0
    Wire.endTransmission();
    Wire.requestFrom(LESABLIER_I2C_ADDRESS, 7); // request seven bytes
    if(Wire.available()) {
        _seconds = _bcd2dec(Wire.read());
        _minutes = _bcd2dec(Wire.read());
        _hours   = _bcd2dec(Wire.read());
        _day     = (Wire.read() & B00000111);
        _date    = _bcd2dec(Wire.read());
        _month   = _bcd2dec(Wire.read()); //msb7 is century overflow
        _year    = _bcd2dec(Wire.read());
    }
}

void LeSablier_::fastUpdate() {
    if((millis() - _lastUpdate) > 100) {
        update();
    }
}

void LeSablier_::updateTemp() {
    //temp registers (11h-12h) get updated automatically every 64s
    Wire.beginTransmission(LESABLIER_I2C_ADDRESS);
    Wire.write(0x11);
    Wire.endTransmission();
    Wire.requestFrom(LESABLIER_I2C_ADDRESS, 2);
    if(Wire.available()) {
        uint8_t tMSB = Wire.read(); //2's complement int portion
        uint8_t tLSB = Wire.read(); //fraction portion
        _temp = (tMSB & B01111111); //do 2's math on Tmsb
        _temp += ( (tLSB >> 6) * 0.25 ); //only care about bits 7 & 8
    }
}

uint8_t LeSablier_::getYear() {
    fastUpdate();
    return _year;
}

uint8_t LeSablier_::getMonth() {
    fastUpdate();
    return _month;
}

uint8_t LeSablier_::getDay() {
    fastUpdate();
    return _day;
}

#ifdef LESABLIER_DAY_NAMES
const char* LeSablier_::getDayStr() {
    return dayNames[getDay()-1];
}
#endif

#ifdef LESABLIER_MONTH_NAMES
const char* LeSablier_::getMonthStr() {
    return monthNames[getMonth()-1];
}
#endif

uint8_t LeSablier_::getDate() {
    fastUpdate();
    return _date;
}

uint8_t LeSablier_::getHours() {
    fastUpdate();
    return _hours;
}

uint8_t LeSablier_::getMinutes() {
    fastUpdate();
    return _minutes;
}

uint8_t LeSablier_::getSeconds() {
    fastUpdate();
    return _seconds;
}

float LeSablier_::getTemp() {
    updateTemp();
    return _temp;
}


void LeSablier_::setYear(uint8_t year) {
    update();
    setAll(_day, _date, _month, year, _hours, _minutes, _seconds);
}

void LeSablier_::setMonth(uint8_t month) {
    update();
    setAll(_day, _date, month, _year, _hours, _minutes, _seconds);
}

void LeSablier_::setDay(uint8_t day) {
    update();
    setAll(day, _date, _month, _year, _hours, _minutes, _seconds);
}

void LeSablier_::setDate(uint8_t date) {
    update();
    setAll(_day, date, _month, _year, _hours, _minutes, _seconds);
}

void LeSablier_::setHours(uint8_t hours) {
    update();
    setAll(_day, _date, _month, _year, hours, _minutes, _seconds);
}

void LeSablier_::setMinutes(uint8_t minutes) {
    update();
    setAll(_day, _date, _month, _year, _hours, minutes, _seconds);
}

void LeSablier_::setSeconds(uint8_t seconds) {
    update();
    setAll(_day, _date, _month, _year, _hours, _minutes, seconds);
}

void LeSablier_::setAll(uint8_t day, uint8_t date, uint8_t month, uint8_t year, uint8_t hours, uint8_t minutes, uint8_t seconds) {
    Wire.beginTransmission(LESABLIER_I2C_ADDRESS);
    Wire.write(0x00);
    Wire.write(_dec2bcd(seconds));
    Wire.write(_dec2bcd(minutes));
    Wire.write(_dec2bcd(hours));
    Wire.write(_dec2bcd(day));
    Wire.write(_dec2bcd(date));
    Wire.write(_dec2bcd(month));
    Wire.write(_dec2bcd(year));
    Wire.endTransmission();
    _day = day;
    _date = date;
    _month = month;
    _year = year;
    _hours = hours;
    _minutes = minutes;
    _seconds = seconds;
}

uint8_t LeSablier_::_bcd2dec(uint8_t bcd) {
    return ((bcd & B11110000) >> 4)*10 + (bcd & B00001111);
}

uint8_t LeSablier_::_dec2bcd(uint8_t dec) {
    return ((dec/10) << 4) | (dec % 10);
}

