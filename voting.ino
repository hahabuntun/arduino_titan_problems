#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int led1_pin = 25;
const int led2_pin = 26;
const int led3_pin = 27;

const int button1_pin = 32;
const int button2_pin = 33;
const int button3_pin = 34;

int person1 = 0;
int person2 = 0;
int person3 = 0;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long debounceDelay = 300;  // Increased debounce time to 300ms

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Voting machine");

  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);

  pinMode(button1_pin, INPUT_PULLUP);
  pinMode(button2_pin, INPUT_PULLUP);
  pinMode(button3_pin, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();

  Serial.print("Button1: ");
  Serial.print(digitalRead(button1_pin));
  Serial.print("\tButton2: ");
  Serial.print(digitalRead(button2_pin));
  Serial.print("\tButton3: ");
  Serial.println(digitalRead(button3_pin));

  if (digitalRead(button1_pin) == LOW && (currentMillis - lastDebounceTime1) > debounceDelay) {
    person1++;
    lastDebounceTime1 = currentMillis;

    lcd.setCursor(0, 1);
    lcd.print("Person1: ");
    lcd.print(person1);

    digitalWrite(led1_pin, HIGH);
    delay(100);
    digitalWrite(led1_pin, LOW);
  }

  if (digitalRead(button2_pin) == LOW && (currentMillis - lastDebounceTime2) > debounceDelay) {
    person2++;
    lastDebounceTime2 = currentMillis;

    lcd.setCursor(0, 2);
    lcd.print("Person2: ");
    lcd.print(person2);

    digitalWrite(led2_pin, HIGH);
    delay(100);
    digitalWrite(led2_pin, LOW);
  }

  if (digitalRead(button3_pin) == LOW && (currentMillis - lastDebounceTime3) > debounceDelay) {
    person3++;
    lastDebounceTime3 = currentMillis;

    lcd.setCursor(0, 3);
    lcd.print("Person3: ");
    lcd.print(person3);

    digitalWrite(led3_pin, HIGH);
    delay(100);
    digitalWrite(led3_pin, LOW);
  }

  delay(50);
}