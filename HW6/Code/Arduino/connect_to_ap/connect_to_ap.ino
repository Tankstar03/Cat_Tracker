#include <WiFi.h>
const char* ssid = "Andy";   /*Replace SSID of your network*/
// const char* ssid2 = "Jason";   /*Replace SSID of your network*/


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
  Serial.begin(115200); /*Baud Rate for serial communication*/
  initWiFi();  /*Initialize WiFi*/
  
}
void loop() {
  Serial.print("Connected Network Signal Strength (Jason)(RSSI): ");
  Serial.println(WiFi.RSSI());  /*Print WiFi signal strength*/
  // delay(50);
  // Serial.print("Connected Network Signal Strength (Andy)(RSSI): ");
  // Serial.println(WiFi.RSSI(*ssid2));  /*Print WiFi signal strength*/
  delay(200);
  // if(int(WiFi.RSSI())>-70){
  //   Serial.println("Cat is near the door");

  // }
  // else{
  //   Serial.println("Cat is far");
  // }
}