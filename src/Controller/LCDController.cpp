#include "LCDController.h"

// Constructor: Initializes the LCDController with specified pins for the LiquidCrystal library
LCDController::LCDController(int rs, int en, int d4, int d5, int d6, int d7)
    : lcd(rs, en, d4, d5, d6, d7) {}

// Initializes the LCD with 16x2 dimensions and clears the display
void LCDController::init()
{
    lcd.begin(16, 2);
    lcd.clear();
}

// Clears the entire LCD display
void LCDController::clear()
{
    lcd.clear();
}

// Prints a message on the LCD at the specified line and column
void LCDController::print(const String &message, int line, int col)
{
    lcd.setCursor(col, line);
    lcd.print(message);
}

// Updates the LCD with two lines of text, clearing it first
void LCDController::update(const String &line1, const String &line2)
{
    clear();
    print(line1, 0, 0);
    print(line2, 1, 0);
}
