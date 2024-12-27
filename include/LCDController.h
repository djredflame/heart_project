#ifndef LCDCONTROLLER_H
#define LCDCONTROLLER_H

#include <LiquidCrystal.h>

// The LCDController class provides an interface for controlling a 16x2 LCD display
class LCDController
{
private:
    LiquidCrystal lcd; // LiquidCrystal object for interacting with the LCD

public:
    // Constructor: Initializes the LCDController with the specified pin configuration
    LCDController(int rs, int en, int d4, int d5, int d6, int d7);

    // Initializes the LCD with 16x2 dimensions and clears the screen
    void init();

    // Clears all content from the LCD screen
    void clear();

    // Prints a message on the LCD at the specified line and column
    void print(const String &message, int line = 0, int col = 0);

    // Updates the LCD with two lines of text, clearing the screen first
    void update(const String &line1, const String &line2 = "");
};

#endif
