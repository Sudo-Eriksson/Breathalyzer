#include <LiquidCrystal.h>

const int rs = 12, E = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // LCD pins
LiquidCrystal lcd(rs, E, d4, d5, d6, d7);

const int MQ3_PIN = A5;  // Pin for the alcohol sensor.
int sensor_value;       // Value from the alcohol sensor.

void setup() {
  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(8, 2);
  lcd.print("Warming");
  lcd.setCursor(0, 1);
  lcd.print("Sensor");
  
  pinMode(MQ3_PIN, INPUT);
  
  Serial.println("Setup started");
  Serial.println("Warming up sensor...");
  
  delay(10000);
  
  Serial.println("Setup done!");
}

void loop() {  
  sensor_value = analogRead(MQ3_PIN);
  
  Serial.println(sensor_value);
    
  if (sensor_value < 120) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sober :(");
    lcd.setCursor(0, 1);
    lcd.print(sensor_value);
  }
  else if (sensor_value > 120 && sensor_value < 400 ){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Booring");
    lcd.setCursor(0, 1);
    lcd.print(sensor_value);
  }
  else if (sensor_value > 400) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Drunk :)");
    lcd.setCursor(0, 1);
    lcd.print(sensor_value);
  }
  
  delay(500);
}

int reading_to_BAC(int reading){
  // Convert MQ-3 reading to BAC.
  }
