#define IR_SENSOR_PIN 4              // GPIO connected to IR OUT pin

void setup() {
  Serial.begin(115200);
  pinMode(IR_SENSOR_PIN, INPUT);     // IR sensor gives digital output

  Serial.println("IR Sensor Test");
}

void loop() {
  int irValue = digitalRead(IR_SENSOR_PIN);  // Read IR sensor state

  if (irValue == LOW) {
    Serial.println("Object / Hand Detected");
  } else {
    Serial.println("No Object");
  }

  delay(500);
}
