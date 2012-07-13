#include <Wire.h>
#include <LeSablier.h>

void setup() {
	Wire.begin();
	Serial.begin(9600);
	LeSablier.begin();
}

void loop() {
	Serial.print(LeSablier.getDayStr());
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
}

