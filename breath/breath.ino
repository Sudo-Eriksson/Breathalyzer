const int MQ3_PIN = 0;  // Pin for the alcohol sensor.
int alk_value;          // Value from the alcohol sensor.

void setup() {
  Serial.begin(9600);
  pinMode(MQ3_PIN, INPUT);
}

void loop() {
  alk_value = analogRead(MQ3_PIN);
  Serial.println(alk_value);
  delay(1000);
}
