#include <LeSablier.h>
#include <Deuligne.h>
#include <Wire.h>

Deuligne lcd;

void setup() {
    Wire.begin();
    LeSablier.begin();
    lcd.init();
    lcd.clear();
    lcd.backLight(true);
    lcd.noCursor();
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print(LeSablier.getHours());
    lcd.print(":");
    lcd.print(LeSablier.getMinutes());
    lcd.print(":");
    lcd.print(LeSablier.getSeconds());
    lcd.print("                "); //clear the rest of the line
    lcd.setCursor(0, 1);
    lcd.print(LeSablier.getDayStr());
    lcd.print(", ");
    lcd.print(LeSablier.getMonth());
    lcd.print("/");
    lcd.print(LeSablier.getDate());
    lcd.print("/");
    lcd.print(LeSablier.getYear());
    lcd.print("                "); //clear the rest of the line
}

