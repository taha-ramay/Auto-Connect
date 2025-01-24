#ifndef auto_connect_H
#define auto_connect_H
#include "auto_connect.h"
#include <WiFi.h>        // Use WiFi.h for ESP32
#include <WebServer.h>   // Use WebServer.h for ESP32
#include <AutoConnect.h> // AutoConnect library for ESP32


class auto_connect
{
private:
    /* data */
public:
    // auto_connect(int a);
    void init();
    void loop();
    // ~auto_connect();
};



// auto_connect::~auto_connect()
// {
// }
void rootpage();
extern auto_connect esp_auto;
#endif