#include "WiFi.h"


// Set your access point network credentials
const char* ssid = "Cat";
void setup() {
   Serial.begin(115200);
  // put your setup code here, to run once:
 Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid);
}

void loop() {
  // put your main code here, to run repeatedly:

}
