#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trig_pin = 5;
const int echo_pin = 18;

const int low_led = 25;
const int mid_led = 26;
const int high_led = 27;


LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(115200);

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, OUTPUT);

  pinMode(low_led, OUTPUT);
  pinMode(mid_led, OUTPUT);
  pinMode(high_led, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);

  long distance = (duration * 0.0343) / 2;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water level: ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  if (distance > 30)
  {
    digitalWrite(low_led, HIGH);
    digitalWrite(mid_led, LOW);
    digitalWrite(high_led, LOW);
  } else if (distance <= 30 && distance > 15)
  {
    digitalWrite(low_led, LOW);
    digitalWrite(mid_led, HIGH);
    digitalWrite(high_led, LOW);
  } else if (distance <= 15)
  {
    digitalWrite(low_led, LOW);
    digitalWrite(mid_led, LOW);
    digitalWrite(high_led, HIGH);
  }
  delay(1000);
}
