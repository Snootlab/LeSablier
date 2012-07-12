#include <Wire.h>
#include <LeSablier.h>
void setup() {
	Wire.begin();
	Serial.begin(9600);
	LeSablier.begin();
}

//Format to set the date:  day   date    month   year    hours  minutes seconds
//Range:                  (0-6) (01-31) (01-12) (00-99) (00-24) (00-59) (00-59)
void loop() {
	if(Serial.available() == 19) { //If something was send (19 is the number of byte sent (see the format above)
		uint8_t day = Serial.read() - '0';
		Serial.read(); //Space
		uint8_t date = str2nb(Serial.read(), Serial.read());
		Serial.read(); //Space
		uint8_t month = str2nb(Serial.read(), Serial.read());
		Serial.read(); //Space
		uint8_t year = str2nb(Serial.read(), Serial.read());
		Serial.read(); //Space
		uint8_t hours = str2nb(Serial.read(), Serial.read());
		Serial.read(); //Space
		uint8_t minutes = str2nb(Serial.read(), Serial.read());
		Serial.read(); //Space
		uint8_t seconds = str2nb(Serial.read(), Serial.read());

		Serial.println(day);
		Serial.println(date);
		Serial.println(month);
		Serial.println(year);
		Serial.println(hours);
		Serial.println(minutes);
		Serial.println(seconds);
		LeSablier.setDay(day);
		LeSablier.setDate(date);
		LeSablier.setMonth(month);
		LeSablier.setYear(year);
		LeSablier.setHours(hours);
		LeSablier.setMinutes(minutes);
		LeSablier.setSeconds(seconds);

		//Or more concisely and fast :
		//LeSablier.setAll(day, date, month, year, hours, minutes, seconds);
		Serial.print("Done");
		Serial.print(Serial.available());
	}
}

uint8_t str2nb(char ch1, char ch2) {
	return (ch1-'0') * 10 + (ch2-'0');
}

