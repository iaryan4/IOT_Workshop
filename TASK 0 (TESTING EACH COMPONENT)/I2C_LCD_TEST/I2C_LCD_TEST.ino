#include <Wire.h>                    // I2C communication library
#include <LiquidCrystal_I2C.h>       // //library-- LiquidCrystal_I2C by Frank de Brabander


// Create LCD object
// 0x27 = I2C address, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(21, 22);                // SDA = GPIO21, SCL = GPIO22
  lcd.init();                        // Initialize LCD
  lcd.backlight();                   // Turn ON backlight

  lcd.setCursor(0, 0);               // Column 0, Row 0
  lcd.print("LCD TEST");

  lcd.setCursor(0, 1);               // Column 0, Row 1
  lcd.print("Working OK");    // expacted output 
}

void loop() {
  // Nothing needed here
}
