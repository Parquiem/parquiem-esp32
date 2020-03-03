#include <ArduinoJson.h>
#include <WiFi.h>
#include "esp32-mqtt.h"

const char* ssid     = "";
const char* password = "";

int IRs1 = 33;
int IRs2 = 32;

char buffer[100];

void setup()
{
    Serial.begin(9600);
      WiFi.begin(ssid, password); // Wait some time to connect to wifi
    for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
        Serial.print(".");
        delay(1000);
    }
    
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
 bool estado1 = digitalRead(IRs1);
 bool estado2 = digitalRead(IRs2);
  StaticJsonDocument<100> doc;
    doc["estado1"] = estado1;
    doc["estado2"] = estado2;
    serializeJson(doc, buffer);
    //publishTelemetry(mqttClient, "/sensors", getDefaultSensor());
    publishTelemetry(buffer);
    
}
