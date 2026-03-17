#include <LiquidCrystal.h>

// LCD pin connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 9, 8);

// Pins
int entryButton = 2;
int exitButton = 3;
int ledPin = 7;

// Variables
int count = 0;
int maxCapacity = 10;

void setup() {
  pinMode(entryButton, INPUT_PULLUP);
  pinMode(exitButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  lcd.begin(16, 2);

  // Welcome Screen
  lcd.setCursor(0, 0);
  lcd.print("Metro System");
  lcd.setCursor(0, 1);
  lcd.print("Welcome!");
  delay(2000);
  lcd.clear();
}

void loop() {

  // Entry Button
  if (digitalRead(entryButton) == LOW) {
    if (count < maxCapacity) {
      count++;
    }
    delay(300);
  }

  // Exit Button
  if (digitalRead(exitButton) == LOW) {
    if (count > 0) {
      count--;
    }
    delay(300);
  }

  // Display Count
  lcd.setCursor(0, 0);
  lcd.print("People: ");
  lcd.print(count);
  lcd.print("   ");  // clears extra digits

  // Display Status
  lcd.setCursor(0, 1);
  if (count >= maxCapacity) {
    lcd.print("Metro FULL  ");
    digitalWrite(ledPin, HIGH);
  } else {
    lcd.print("Seats Free  ");
    digitalWrite(ledPin, LOW);
  }
}