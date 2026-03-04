int led_1 = 16;
int led_2 = 17;
int led_3 = 18;
int led_4 = 19;
int led_5 = 21;

#define LIGHT_SENSOR_PIN 36


void setup() {
  Serial.begin(9600);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
}

void loop() {
  int analog_value = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog value: ");
  Serial.print(analog_value);

  if (analog_value < 40)
  {
    Serial.print(" => DARK");
    digitalWrite(led_1, HIGH);  
  }
  else if (analog_value < 800)
  {
    Serial.print(" => DIM");
    digitalWrite(led_2, HIGH);  
  }
  else if (analog_value < 2000)
  {
    Serial.print(" => LIGHT");
    digitalWrite(led_3, HIGH);  
  }
  else if (analog_value < 3200)
  {
    Serial.print(" => BRIGHT");
    digitalWrite(led_4, HIGH);  
  }
  else
  {
    Serial.print(" => VERY BRIGHT");
    digitalWrite(led_5, HIGH);  
  }
  delay(100);
}
