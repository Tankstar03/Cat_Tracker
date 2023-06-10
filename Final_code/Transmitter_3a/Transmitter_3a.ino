

#include <WiFi.h>
#include <Wire.h>
const char* ssid = "Cat";   /*Replace SSID of your network*/
int rssi = 12;

void initWiFi() {
  WiFi.mode(WIFI_STA);  /*Initialize ESP32 WiFi in station mode*/
  WiFi.begin(ssid); /*Begin WiFi connection*/
  // WiFi.begin(ssid2); /*Begin WiFi connection*/
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());  /*Print local IP address of ESP32*/
}

void setup() {
  Serial.begin(115200);
  Wire.begin(8);                // join i2c bus with address #8
  
  initWiFi();
}

void loop() {
  delay(100);
  rssi = (-1)*int(WiFi.RSSI());
  Serial.println(rssi);
  
  Wire.onRequest(requestEvent); // register event
}


// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(rssi); // respond with message of 6 bytes
  // as expected by master
}