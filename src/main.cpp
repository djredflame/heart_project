#include <Arduino.h>
#include "LCDController.h"

#define RS 12
#define EN 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

LCDController lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
  lcd.init();
}

void loop()
{
  lcd.print("Hello, World!", 0, 0);
  lcd.print("Arduino LCD!", 1, 0);
  delay(3000);
  lcd.update("Test", "Test Two");
  delay(3000);
}
