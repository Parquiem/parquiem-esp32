#include <ArduinoJson.h>
#include "esp32-mqtt.h"

int IRs1 = 33;
int IRs2 = 32;

char buffer[100];

void setup()
{
    Serial.begin(9600);
  pinMode(IRs1, INPUT);
  pinMode(IRs2, INPUT);
    setupCloudIoT();

}

unsigned long lastMillis = 0;
 
void loop() {
    
  mqtt->loop();
  delay(10);  // <- fixes some issues with WiFi stability
 
  if (!mqttClient->connected()) {
    connect();
  }
 
StaticJsonDocument<100> doc;
    int estado1 = digitalRead(IRs1);
    doc["estado1"] = estado1;
    Serial.println(estado1);
    int estado2 = digitalRead(IRs2);
    doc["estado2"] = estado2;
    Serial.println(estado2);
    serializeJson(doc, buffer);
    //publishTelemetry(mqttClient, "/sensors", getDefaultSensor());
    publishTelemetry(buffer);
    delay(1000);
  
}

