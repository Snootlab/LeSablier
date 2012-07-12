#ifndef LESABLIER_H
#define LESABLIER_H

#include <Arduino.h>

class LeSablier_ {
	public:
		void begin();
		void end();
		void update();
		void fastUpdate();
		void updateTemp();
		uint8_t getYear();
		uint8_t getMonth();
		uint8_t getDay();
		uint8_t getDate();
		uint8_t getHours();
		uint8_t getMinutes();
		uint8_t getSeconds();
		float getTemp();
		
		void setYear(uint8_t year);
		void setMonth(uint8_t month);
		void setDay(uint8_t day);
		void setDate(uint8_t date);
		void setHours(uint8_t hours);
		void setMinutes(uint8_t minutes);
		void setSeconds(uint8_t seconds);

		void setAll(uint8_t day, uint8_t date, uint8_t month, uint8_t year, uint8_t hours, uint8_t minutes, uint8_t seconds);

	private:
		uint8_t _year;
		uint8_t _month;
		uint8_t _day;
		uint8_t _date;
		uint8_t _hours;
		uint8_t _minutes;
		uint8_t _seconds;
		float _temp;

		unsigned long _lastUpdate;

		uint8_t _bcd2dec(uint8_t bcd);
		uint8_t _dec2bcd(uint8_t dec);
};

extern LeSablier_ LeSablier;

		
#endif

