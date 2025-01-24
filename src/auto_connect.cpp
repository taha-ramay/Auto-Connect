#include "auto_connect.h"
#include <WiFi.h>      // Use WiFi.h for ESP32
#include <WebServer.h> // Use WebServer.h for ESP32
#include <AutoConnect.h>
auto_connect esp_auto;
WebServer Server; // Use WebServer for ESP32
AutoConnect Portal(Server);
AutoConnectConfig Config;

AutoConnectInput temp_increase("temp","","Temperature","^[0-9]+$","", AC_Tag_BR , AC_Input_Number,"display: flex; justify-content: space-between; margin-bottom: 10px;");
AutoConnectInput LED_intensity("LED", "", "intensity", "^[0-9]+$", " ", AC_Tag_BR, AC_Input_Number,"display: flex; justify-content: space-between; margin-bottom: 10px;" );
AutoConnectInput wifi_1("WIFI", "", "wifi", "^[A-Za-z]+$", " ", AC_Tag_BR, AC_Input_Text, "display: flex; justify-content: space-between; margin-bottom: 10px;");
AutoConnectInput password("password", "", "pass", "^[0-9]+$", " ", AC_Tag_BR, AC_Input_Number, "display: flex; justify-content: space-between; margin-bottom: 10px;");
AutoConnectSubmit submit("Submit", "Submit", "/submit", AC_Tag_BR);
AutoConnectAux setting_update("/setting_update", "Data Controller", true,
                              {temp_increase,
                               LED_intensity,
                               wifi_1,
                               password,
                               submit});
//////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////

AutoConnectText description("describe", "all the answers has been added ", "<h4>the data has been saved </h4>", "all the values are saved", AC_Tag_BR);
AutoConnectButton button("button", "LED", "", AC_Tag_BR);
AutoConnectElement new_line(" ", " ", AC_Tag_BR);
AutoConnectSubmit graph_submit("Graph", "Show Graph", "/show_graph", AC_Tag_BR);

AutoConnectAux Submit1("/submit", "DATA SUBMITTED", false, {description, button, new_line});

String handleNameInput(AutoConnectAux &aux, PageArgument &args)
{
  String temp_increase1 = temp_increase.value; // Get the input value
  String led_intensity = LED_intensity.value;
  String wifi_11 = wifi_1.value;
  String password12 = password.value;
  Serial.println("User Name: " + temp_increase1);
  Serial.println("led_intensity " + led_intensity);
  Serial.println("wifi " + wifi_11);
  Serial.println("password" + password12); // Print to Serial Monitor
  return String();                         // Return empty if no redirect or response is needed
}

void led_blink(AutoConnectButton &me, AutoConnectAux &ledOnOff)
{
  String Led_Print = me.value;
  Serial.println(" the led button has pressed");
  Serial.println("Button pressed" + Led_Print);

}
void auto_connect ::init()
{

  Portal.join({setting_update, Submit1});
  Submit1.on(handleNameInput);
  button.on(led_blink);
  Config.reconnectInterval = 0;

  Config.autoRise = true;
  Config.immediateStart = true;
  Portal.config(Config);

  if (Portal.begin())
  {
    Serial.println("WiFi connected: " + WiFi.localIP().toString());
  }
  else
  {
    Serial.println("Failed to connect to WiFi.");
  }
}
