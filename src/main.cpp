#include <ESP8266WiFi.h>
#include <lib/wifi/wifi.h>
#include <lib/mqtt/mqtt.h>

Mqtt mqtt_client;
// {
//   // Loop until we're reconnected
//   while (!client.connected())
//   {
//     Serial.print("Attempting MQTT connection...");
//     // Attempt to connect
//     if (client.connect("ESP8266Client"))
//     {
//       Serial.println("connected");
//       // Subscribe to a topic
//       client.subscribe("esp/test");
//     }
//     else
//     {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 5 seconds");
//       // Wait 5 seconds before retrying
//       delay(5000);
//     }
//   }
// }

void setup()
{
  Serial.begin(115200);
  setup_wifi();
  mqtt_client.setup();
}

void loop()
{
  mqtt_client.loop();

  // mqtt_client.publish("esp/test", "Hello from ESP8266");
  // delay(2000); // Publish every 2 seconds
}
