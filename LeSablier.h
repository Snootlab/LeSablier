/**
 * \file LeSablier.h
 * \brief Main file
 * \author Théophile `TWal` Wallez
 */

/**
 * \mainpage LeSablier API reference
 * \section Requirements
 * * Arduino: http://arduino.cc
 * * Le Sablier: http://shop.snootlab.com/lang-en/snootlab-shields/203-le-sablier.html
 * \section Examples
 * * SerialClock: a clock communicating via serial port
 * * DeuligneClock: a clock displaying the time with the Deuligne
 * * SetTime: Change the time via serial port
 * * Language: Demonstration of LeSablier's language support
 * \section Installation
 * Like every other arduino library: http://arduino.cc/en/Hacking/Libraries
 */

#ifndef LESABLIER_H
#define LESABLIER_H

#include <Arduino.h>
#include "LeSablierConfig.h"

/**
 * \class LeSablier_
 * \brief The class that communicate with LeSablier
          /!\ Don't instanciate it! Use LeSablier object instead (note the trailing underscore in the class name)
 */
class LeSablier_ {
    public:
        /**
         * \brief Begin the communication with LeSablier
         */
        void begin();

        /**
         * \brief End the communication with LeSablier
         */
        void end();

        /**
         * \brief Force update (request the time frop LeSablier) (internal)
         */
        void update();

        /**
         * \brief Force update, but only if required (internal)
         */
        void fastUpdate();

        /**
         * \brief Update the temperature (internal)
         */
        void updateTemp();

        /**
         * \brief Request the current year. Range: 0-99. 0 is year 2000
         * \return The current year
         */
        uint8_t getYear();

        /**
         * \brief Request the current month. Range: 1-12. 1 is January
         * \return The current month
         */
        uint8_t getMonth();

        /**
         * \brief Request the current day of the week. Range: 1-7. 1 is Monday
         * \return The current day of the week
         */
        uint8_t getDay();

        /**
         * \brief Request the current day of the month. Range: 1-31.
         * \return The current day of the month
         */
        uint8_t getDate();

        /**
         * \brief Request the current hour. Range: 0-23.
         * \return The current hour
         */
        uint8_t getHours();

        /**
         * \brief Request the current minute. Range: 0-59.
         * \return The current minute
         */
        uint8_t getMinutes();

        /**
         * \brief Request the current second. Range: 0-59.
         * \return The current second
         */
        uint8_t getSeconds();

        /**
         * \brief Request the current temperature. /!\ Update every 64s
         * \return The current temperature
         */
        float getTemp();

        /**
         * \brief Change the year
         * \param year The year
         */
        void setYear(uint8_t year);

        /**
         * \brief Change the month
         * \param month The month
         */
        void setMonth(uint8_t month);

        /**
         * \brief Change the day of the week
         * \param day The day of the week
         */
        void setDay(uint8_t day);

        /**
         * \brief Change the day of the month
         * \param date The day of the month
         */
        void setDate(uint8_t date);

        /**
         * \brief Change the hour
         * \param hours The hour
         */
        void setHours(uint8_t hours);

        /**
         * \brief Change the minute
         * \param minutes The minute
         */
        void setMinutes(uint8_t minutes);

        /**
         * \brief Change the second
         * \param seconds The second
         */
        void setSeconds(uint8_t seconds);

        /**
         * \brief Change all the parameters!
         * \param day The day of the week
         * \param date The day of the month
         * \param month The month
         * \param year The year
         * \param hours The hour
         * \param minutes The minute
         * \param seconds The second
         */
        void setAll(uint8_t day, uint8_t date, uint8_t month, uint8_t year, uint8_t hours, uint8_t minutes, uint8_t seconds);

#ifdef LESABLIER_DAY_NAMES
        /**
         * \brief Request the current day of the week, as string.
                  Change the language trough LeSablierConfig.h
         * \return The current day of the week as string
         */
        const char* getDayStr();
#endif
#ifdef LESABLIER_MONTH_NAMES
        /**
         * \brief Request the current month, as string.
                  Change the language trough LeSablierConfig.h
         * \return The current month as string
         */
        const char* getMonthStr();
#endif

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


/**
 * \var LeSablier
 * \brief The object to use to communicate with LeSablier
 */
extern LeSablier_ LeSablier;


#endif

