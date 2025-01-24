// AutoConnect library for ESP32
#include <auto_connect.h>

void setup()
{
  Serial.begin(115200);
  delay(1000);
  esp_auto.init();

}
// Server.send();//
void loop()
{
  // Handle client requests for AutoConnect

  esp_auto.loop();
}
////////////////
/////////////////////////////////
////////////////////////////////\///////////
/////////

