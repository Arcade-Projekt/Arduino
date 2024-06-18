#include <LiquidCrystal.h>
#define TEMPRATURE_SENSOR 0
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


void setup() {
  lcd.begin(16, 2);
  analogRead(TEMPRATURE_SENSOR);
}

void loop() {

const float BETA = 3950; // should match the Beta Coefficient of the thermistor
int analogValue = analogRead(A0);
float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
lcd.print("Current Temp: ");
lcd.print(celsius);
lcd.setTextInsertionMode(LEFT_TO_RIGHT)
delay(1000);
lcd.clear();
}