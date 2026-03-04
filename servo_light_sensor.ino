#include <ESP32Servo.h>

#define PIN_LDR 36
#define PIN_SERVO 26

Servo servo;


void setup() {
  Serial.begin(9600);
  servo.attach(PIN_SERVO);
}

void loop() {
  int analog_value = analogRead(PIN_LDR);

  int angle = map(analog_value, 0, 4095, 0, 180);

  servo.write(angle);
  delay(100);
}

