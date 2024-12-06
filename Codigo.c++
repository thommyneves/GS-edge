#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

// Configurações Wi-Fi
const char* ssid = "Wokwi-GUEST";  // Rede Wi-Fi do Wokwi
const char* password = "";

// Configurações MQTT
const char* mqtt_server = "test.mosquitto.org";  // Broker público MQTT
const char* topic_temp = "test/temperature";
const char* topic_hum = "test/humidity";

// Inicializações
WiFiClient espClient;
PubSubClient client(espClient);
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// LED indicador
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();
  connectWiFi();
  client.setServer(mqtt_server, 1883);
}

void connectWiFi() {
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado!");
      digitalWrite(LED_PIN, HIGH);
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp)) {
    client.publish(topic_temp, String(temp).c_str());
    Serial.println("Temperatura enviada: " + String(temp) + "°C");
  }
  if (!isnan(hum)) {
    client.publish(topic_hum, String(hum).c_str());
    Serial.println("Umidade enviada: " + String(hum) + "%");
  }
  delay(2000);
}
