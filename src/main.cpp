// Learn about the ESP32 WiFi simulation in
// https://docs.wokwi.com/guides/esp32-wifi
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "env.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);


#define UTC_OFFSET     0
#define UTC_OFFSET_DST 0

void setup() {

Serial.begin(9600); 
 LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
 WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  // put your setup code here, to run once:
}

void loop() {
  HTTPClient http;
  http.begin(endpoint.c_str());
  http.addHeader("api-key",api_key);
  int httpResponseCode = http.GET();
  
   if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
String responseBody = http.getString();

JsonDocument doc;

DeserializationError error = deserializeJson(doc, responseBody);

if (error) {
  Serial.print("deserializeJson() failed: ");
  Serial.println(error.c_str());
  return;
}

const char* line_1 = doc[F("line_1")]; // "line one"
const char* line_2 = doc[F("line_2")]; // "line two"

    LCD.setCursor(0, 0);
    LCD.println(line_1);
    LCD.setCursor(0, 1);
    LCD.println(line_2);
    

}
else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  
  // Free resources
  http.end();

  



// put function definitions here:
}
