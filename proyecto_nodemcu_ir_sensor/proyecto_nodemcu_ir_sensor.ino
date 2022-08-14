#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLd0V7iD82"
#define BLYNK_DEVICE_NAME "New Template"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "6mCmSCcasZXm3cHiy8QPR6AJ5RBObUHo";
char ssid[] = "The Ghost Warriors S";
char pass[] = "4378947297";

int IR_sensor = D1;
int LED = D7;

WidgetLED led1(V1);// Virtual Pin V2
BlynkTimer timer;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(IR_sensor, INPUT);
  Serial.begin(9600);
  timer.setInterval(300L, sensor1);
  Blynk.begin(auth, ssid, pass/*, "blynk-cloud.com", 80*/);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}

void sensor1(){
  int value = digitalRead(IR_sensor);
  if(value == LOW){
    led1.on();
    digitalWrite(LED,HIGH);
  }
  else{
    led1.off();
    digitalWrite(LED,LOW);
  }  
}
