/*
  ================================
  LCD + DHT11 TEST
  ================================

  This code keeps the LCD working
  and ADDS the DHT11 temperature
  and humidity sensor.

  Required Libraries:
  - LiquidCrystal_I2C
  - DHT sensor library (Adafruit)
  - Adafruit Unified Sensor
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// -------- Pin Definitions --------
#define DHTPIN 5
#define DHTTYPE DHT11

// -------- Object Creation --------
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(21, 22);      // Start I2C for LCD
  lcd.init();
  lcd.backlight();

  dht.begin();             // Initialize DHT11 sensor

  lcd.setCursor(0, 0);
  lcd.print("DHT11 TEST");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Read temperature and humidity from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Clear old LCD data
  lcd.clear();

  // Display temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  // Display humidity
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000);  // DHT11 needs slow reading
}
