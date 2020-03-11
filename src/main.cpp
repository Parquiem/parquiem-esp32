#include <ArduinoJson.h>
#include "esp32-mqtt.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int IRs1 = 33;
int IRs2 = 32;
int totalColumns = 16;
int totalRows = 2;
LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);

char buffer[100];

void setup()
{
    Wire.begin();
    Serial.begin(9600);
    Serial.println("ESP32 scanning for I2C devices");
lcd.init(); 
lcd.backlight();
 pinMode(IRs1, INPUT);
  pinMode(IRs2, INPUT);
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
    byte error_i2c, address_i2c;
int I2C_Devices;
Serial.println("Scanning started");
I2C_Devices = 0;
for(address_i2c = 1; address_i2c < 127; address_i2c++ )
{
Wire.beginTransmission(address_i2c);
error_i2c = Wire.endTransmission();
if (error_i2c == 0) {
Serial.print("I2C device found at address_i2c 0x");
if (address_i2c<16) 
{
Serial.print("0");
}
Serial.println(address_i2c,HEX);
I2C_Devices++;
}
else if (error_i2c==4) 
{
Serial.print("Unknow error_i2c at address_i2c 0x");
if (address_i2c<16) 
{
Serial.print("0");
}
Serial.println(address_i2c,HEX);
} 
}
if (I2C_Devices == 0) 
{
Serial.println("No I2C device connected \n");
}
else {
Serial.println("done I2C device searching\n");
}
int estado1 = digitalRead(IRs1);
int estado2 = digitalRead(IRs2);
lcd.setCursor(0,0);
lcd.print("IR 1        IR 2");
if (estado1 == LOW && estado2 == LOW){
lcd.setCursor(0,1);
lcd.print("Ocup        Ocup");
delay(1000);
lcd.clear();
}
if (estado1 == HIGH && estado2 == HIGH){
lcd.setCursor(0,1);
lcd.print("Disp        Disp");
delay(1000);
lcd.clear();
}
if (estado1 == HIGH && estado2 == LOW){
lcd.setCursor(0,1);
lcd.print("Disp        Ocup");
delay(1000);
lcd.clear();
}     
if (estado1 == LOW && estado2 == HIGH){
lcd.setCursor(0,1);
lcd.print("Ocup        Disp");
delay(1000);
lcd.clear();
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

