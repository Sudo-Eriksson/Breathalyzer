#include <PololuHD44780.h>
PololuHD44780 lcd(7, 6, 5, 4, 3, 2); 

const int MQ3_PIN = 0;  // Pin for the alcohol sensor.
int sensor_value;       // Value from the alcohol sensor.

void setup() {
  Serial.begin(9600);
  pinMode(MQ3_PIN, INPUT);

  lcd.clear();
}

void loop() {
  sensor_value = analogRead(MQ3_PIN);
  
  Serial.println(sensor_value);
  
  if (sensor_value < 120) {
    lcd.print(sensor_value);
    lcd.gotoXY(0, 1);
    lcd.print("Nykter");
  }
  else if (sensor_value > 120 && sensor_value < 400 ){
    lcd.print(sensor_value);
    lcd.gotoXY(0, 1);
    lcd.print("Booring");
  }
  else if (sensor_value > 400) {
    lcd.print(sensor_value);
    lcd.gotoXY(0, 1);
    lcd.print("DRUNK");
  }
  
  delay(1000);
}
