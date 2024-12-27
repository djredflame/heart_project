#ifndef LCDCONTROLLER_H
#define LCDCONTROLLER_H

#include <LiquidCrystal.h>

class LCDController
{
private:
    LiquidCrystal lcd;

public:
    LCDController(int rs, int en, int d4, int d5, int d6, int d7);
    void init();
    void clear();
    void print(const String &message, int line = 0, int col = 0);
    void update(const String &line1, const String &line2 = "");
};

#endif