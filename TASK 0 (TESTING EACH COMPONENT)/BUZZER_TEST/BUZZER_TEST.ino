#define BUZZER_PIN 23                // GPIO connected to buzzer

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);       // Set buzzer as output
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH);    // Turn buzzer ON
  delay(500);

  digitalWrite(BUZZER_PIN, LOW);     // Turn buzzer OFF
  delay(500);
}
