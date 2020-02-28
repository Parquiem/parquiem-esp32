#include <ArduinoJson.h>

#include "esp32-mqtt.h"

char buffer[100];

void setup()
{
    Serial.begin(9600);
    setupCloudIoT();

}

unsigned long lastMillis = 0;
 
void loop() {
  mqtt->loop();
  delay(10);  // <- fixes some issues with WiFi stability
 
  if (!mqttClient->connected()) {
    connect();
  }
 
  if (millis() - lastMillis > 60000) {
    Serial.println("Publishing value");
    lastMillis = millis();
    float temp = 29;
    float hum = 35;
    StaticJsonDocument<100> doc;
    doc["temp"] = temp;
    doc["humidity"] = hum;
    serializeJson(doc, buffer);
    //publishTelemetry(mqttClient, "/sensors", getDefaultSensor());
    publishTelemetry(buffer);
  }
}