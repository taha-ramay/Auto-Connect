#include <WiFi.h>        // Use WiFi.h for ESP32
#include <WebServer.h>   // Use WebServer.h for ESP32
#include <AutoConnect.h> // AutoConnect library for ESP32
#include <auto_connect.h>

void setup()
{
  Serial.begin(115200);
  delay(1000);
  esp_auto.init();
  //  Config.autoReconnect = true;    //
  //  Config.homeUri = "/home";
  // Config.portalTimeout = 1000000; //
  // Portal.config(Config);
  // Aux1.add(customtext);
  // Config.autoReconnect = true;///
  // Portal.config(Config);
  // Aux1.add(input);
  // Aux1.add(button);

  // Portal.join({Aux1, Aux2});
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

