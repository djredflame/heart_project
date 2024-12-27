#include "LCDController.h"

LCDController::LCDController(int rs, int en, int d4, int d5, int d6, int d7)
    : lcd(rs, en, d4, d5, d6, d7) {}

void LCDController::init()
{
    lcd.begin(16, 2);
    lcd.clear();
}

void LCDController::clear()
{
    lcd.clear();
}

void LCDController::print(const String &message, int line, int col)
{
    lcd.setCursor(col, line);
    lcd.print(message);
}

void LCDController::update(const String &line1, const String &line2)
{
    clear();
    print(line1, 0, 0);
    print(line2, 1, 0);
}