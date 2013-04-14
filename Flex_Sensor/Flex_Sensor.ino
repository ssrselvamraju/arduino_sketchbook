const int sensorPin = A2;    // pin that the sensor is attached to
int sensorValue = 0;         // the sensor value

void setup() {
 
  Serial.begin(9600);

 }

void loop() {            
  //analogReference(INTERNAL);
  sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);
delay(50);

}
