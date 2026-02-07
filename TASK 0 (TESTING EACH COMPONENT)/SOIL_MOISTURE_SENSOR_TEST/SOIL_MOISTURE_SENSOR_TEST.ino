#define MOISTURE_ANALOG_PIN 13        // GPIO connected to AO pin

void setup() {
  Serial.begin(115200);              // Serial monitor for values
  Serial.println("Moisture Sensor Test");
}

void loop() {
  int moistureValue = analogRead(MOISTURE_ANALOG_PIN);  // Read analog value

  Serial.print("Moisture Raw Value: ");
  Serial.println(moistureValue);     // 0–4095 (ESP32 ADC)

  delay(1000);
}
// Tipical values of soil moisture sensor 
//Dry soil ~3000-4095
//Wet soil ~1000-2000

