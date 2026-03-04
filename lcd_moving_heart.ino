#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, heart);

  lcd.setCursor(0, 0);
  lcd.print("I love you");

  Serial.begin(115200);
  Serial.println("Hello, ESP32!");


}

void loop() {
  for (int pos = 0; pos < 20; pos++)
  {
    lcd.clear();
    lcd.setCursor(pos, 1);
    lcd.write(byte(0));
    delay(300);
  }
}
