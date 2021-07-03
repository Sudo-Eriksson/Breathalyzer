const int MQ3_PIN = A5;  // Pin for the alcohol sensor.
int sensor_value;       // Value from the alcohol sensor.
int loops = 20;

void setup() {
  Serial.begin(9600);
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
    // LCD = NYKTER
  }
  else if (sensor_value > 120 && sensor_value < 400 ){
    // LCD= Booring
  }
  else if (sensor_value > 400) {
    //LCD = DRUNK
  }
  
  delay(200);
}

int reading_to_BAC(int reading){
  // Convert MQ-3 reading to BAC.
  }
