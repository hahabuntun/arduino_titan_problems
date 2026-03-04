#include <ESP32Servo.h>

#define SERVO_PIN 26

Servo servoMotor;


void setup() {
  servoMotor.attach(SERVO_PIN);
}

void loop() {
  for (int pos = 0; pos <= 180; pos++)
  {
    servoMotor.write(pos);
    delay(15);
  }

  for (int pos = 180; pos >= 0; pos -= 1)
  {
    servoMotor.write(pos);
    delay(15);
  }
}
