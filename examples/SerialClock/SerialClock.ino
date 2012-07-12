#include <Wire.h>
#include <LeSablier.h>

char weekDays[7][4] = {
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat",
	"Sun"
};

void setup() {
	Wire.begin();
	Serial.begin(9600);
	LeSablier.begin();
}

void loop() {
	Serial.print(weekDays[LeSablier.getDay()]);
	Serial.print(", ");
	Serial.print(LeSablier.getMonth());
	Serial.print("/");
	Serial.print(LeSablier.getDate());
	Serial.print("/");
	Serial.print(LeSablier.getYear());
	Serial.print(" - ");
	Serial.print(LeSablier.getHours());
	Serial.print(":");
	Serial.print(LeSablier.getMinutes());
	Serial.print(":");
	Serial.print(LeSablier.getSeconds());
	Serial.print(" - Temp : ");
	Serial.println(LeSablier.getTemp());

	delay(1000);
}

