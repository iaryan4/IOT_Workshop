/*
  ================================
  LCD + DHT11 + IR SENSOR
  ================================

  This code keeps:
  ✔ LCD
  ✔ DHT11

  And ADDS:
  ✔ IR obstacle / proximity sensor
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// -------- Pin Definitions --------
#define DHTPIN 5
#define DHTTYPE DHT11
#define IR_PIN 4

// -------- Object Creation --------
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  dht.begin();                 // Start DHT11
  pinMode(IR_PIN, INPUT);      // IR sensor output pin

  lcd.setCursor(0, 0);
  lcd.print("IR + DHT TEST");
  delay(1500);
  lcd.clear();
}

void loop() {
  int irState = digitalRead(IR_PIN);   // Read IR sensor

  // If object (hand) is detected
  if (irState == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Object Detected");
    delay(1000);
    return;
  }

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");

  delay(2000);
}
