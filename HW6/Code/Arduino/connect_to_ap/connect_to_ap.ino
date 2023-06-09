#include <WiFi.h>
const char* ssid = "Jason";   /*Replace SSID of your network*/

void initWiFi() {
  WiFi.mode(WIFI_STA);  /*Initialize ESP32 WiFi in station mode*/
  WiFi.begin(ssid); /*Begin WiFi connection*/
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
  Serial.print("Connected Network Signal Strength (RSSI): ");
  Serial.println(WiFi.RSSI());  /*Print WiFi signal strength*/
  delay(200);
  if(int(WiFi.RSSI())>-70){
    Serial.println("Cat is near the door");

  }
  else{
    Serial.println("Cat is far");
  }
}