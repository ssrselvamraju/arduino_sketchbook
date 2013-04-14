#include <ros.h>
#include<std_msgs/Int32.h>
#include<std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::Int32 int32_msg;
std_msgs::String str_msg;

ros::Publisher fsensorVal("fsensorVal", &int32_msg);
ros::Publisher stopMsg("stopMsg", &str_msg);

const int sensorPin = A2;    // pin that the sensor is attached to
int sensorValue = 0;         // the sensor value
char sendingMsg[15] = "Stop the motor";

void setup() {
  
  nh.initNode();
  nh.advertise(fsensorVal);
  nh.advertise(stopMsg);
//  Serial.begin(9600);

 }

void loop() {            
 // analogReference(INTERNAL);
  sensorValue = analogRead(sensorPin);
  int32_msg.data = sensorValue;
  fsensorVal.publish( &int32_msg );
  
  if(sensorValue > 700)
  {
    str_msg.data = sendingMsg;
    stopMsg.publish( &str_msg );
    
  }
  
  
  nh.spinOnce();
  
 // Serial.println(sensorValue);
delay(50);

}
