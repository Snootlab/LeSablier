#include <Wire.h>
#include <LeSablier.h>

//To modify LeSablier's language, just see libraries/LeSablier/LeSablierConfig.h

void setup() {
    Wire.begin();
    Serial.begin(9600);
    LeSablier.begin();
}

void loop() {
    Serial.print("Day name: ");
    Serial.print(LeSablier.getDayStr());
    Serial.print(" - Month name: ");
    Serial.println(LeSablier.getMonthStr());

    delay(10000);
}

