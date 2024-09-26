#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class Mqtt
{
public:
  Mqtt();
  void setup();
  void reconnect();
  static void callback(char *topic, byte *payload, unsigned int length);
  void loop();
  void publish(char *topic, char *payload);

private:
  WiFiClient espClient;
  PubSubClient client;
};