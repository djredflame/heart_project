// LCDController.h
#ifndef LCDCONTROLLER_H
#define LCDCONTROLLER_H

#include <LiquidCrystal.h>

class LCDController
{
private:
    LiquidCrystal lcd;

public:
    LCDController(int rs, int en, int d4, int d5, int d6, int d7)
        : lcd(rs, en, d4, d5, d6, d7) {}

    void init()
    {
        lcd.begin(16, 2);
        lcd.clear();
    }

    void clear()
    {
        lcd.clear();
    }

    void print(const String &message, int line = 0, int col = 0)
    {
        lcd.setCursor(col, line);
        lcd.print(message);
    }

    void update(const String &line1, const String &line2 = "")
    {
        clear();
        print(line1, 0, 0);
        print(line2, 1, 0);
    }
};

#endif
