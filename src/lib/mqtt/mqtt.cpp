#include "mqtt.h"

// WiFiClient espClient;
// PubSubClient client(espClient);

const char *mqtt_server = "10.10.10.162";

Mqtt::Mqtt() : client(espClient)
{
}

void Mqtt::setup()
{
  client.setServer(mqtt_server, 1883);
  client.setCallback(Mqtt::callback);
}

// Function to handle received messages
void Mqtt::callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

// Function to connect to the MQTT broker
void Mqtt::reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client"))
    {
      Serial.println("connected");
      // Subscribe to a topic
      client.subscribe("esp/test");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void Mqtt::loop()
{
  if (!client.connected())
  {
    Serial.print("MQTT Connection failed, state: ");
    Serial.println(client.state());
    reconnect();
  }
  client.loop();
}

void Mqtt::publish(char *topic, char *payload)
{
  client.publish(topic, payload);
}