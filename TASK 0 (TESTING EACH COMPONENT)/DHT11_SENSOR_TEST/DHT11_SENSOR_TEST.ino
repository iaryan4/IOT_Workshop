#include "DHT.h"                     // DHT sensor library (by Adafruit)

#define DHT_DATA_PIN 5               // GPIO where DHT11 DATA is connected
#define DHT_TYPE DHT11               // Using DHT11 sensor

DHT dht(DHT_DATA_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);              // Start serial monitor
  dht.begin();                       // Initialize DHT sensor

  Serial.println("DHT11 Test Started");
}

void loop() {
  float humidity = dht.readHumidity();       // Read humidity
  float temperature = dht.readTemperature(); // Read temperature in Celsius

  // Check if reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read DHT11");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);                       // DHT11 needs slow reading
}
