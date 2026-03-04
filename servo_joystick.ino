#include <ESP32Servo.h>

#define VRX_PIN 36
#define VRY_PIN 39
#define SERVO_X_PIN 13
#define SERVO_Y_PIN 25

Servo xServo;
Servo yServo;


void setup() {
  Serial.begin(9600);
  xServo.attach(SERVO_X_PIN);
  yServo.attach(SERVO_Y_PIN);
}

void loop() {
  int valueX = analogRead(VRX_PIN);
  int valueY = analogRead(VRY_PIN);

  int xAngle = map(valueX, 0, 4095, 0, 180);
  int yAngle = map(valueY, 0, 4095, 0, 180);

  xServo.write(xAngle);
  yServo.write(yAngle);

  Serial.print("Joystick: ");
  Serial.print(valueX);
  Serial.print(", ");
  Serial.print(valueY);
  Serial.print(" => Servo motor: ");
  Serial.print(xAngle);
  Serial.print(", ");
  Serial.print(yAngle);
}
