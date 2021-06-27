// Taken from https://www.dfrobot.com/blog-903.html

void setup()
{
   Serial.begin(9600);
}
 
void loop()
{
    float sensor_volt;
    float RS; //  Get the value of RS via in a clear air
    float R0;  // Get the value of R0 via in Alcohol
    float sensorValue;
 
    for(int i = 0 ; i < 100 ; i++)
    {
        sensorValue = sensorValue + analogRead(A0);
    }
 
    sensorValue = sensorValue/100.0;     //get average of reading
    sensor_volt = sensorValue/1024*5.0;
    RS = (5.0-sensor_volt)/sensor_volt; // 
    R0 = RS/60.0; // 60 is found using interpolation
    Serial.print("R0 = ");
    Serial.println(R0);
    delay(1000);
 
}
