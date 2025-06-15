#ifndef LCDCONTROLLER_H
#define LCDCONTROLLER_H

#include <LiquidCrystal.h>

// The LCDController class provides an interface for controlling a 16x2 LCD display
class LCDController
/**
 * @file LCDController.h
 * @brief Header file for the LCDController class.
 *
 * This file contains the declaration of the LCDController class, which provides
 * methods to interact with an LCD screen using the LiquidCrystal library.
 */

{
private:
    LiquidCrystal lcd; ///< LiquidCrystal object for interacting with the LCD

public:
    /**
     * @brief Constructor: Initializes the LCDController with the specified pin configuration.
     *
     * @param rs Register select pin.
     * @param en Enable pin.
     * @param d4 Data pin 4.
     * @param d5 Data pin 5.
     * @param d6 Data pin 6.
     * @param d7 Data pin 7.
     */
    LCDController(int rs, int en, int d4, int d5, int d6, int d7);

    /**
     * @brief Initializes the LCD with 16x2 dimensions and clears the screen.
     */
    void init();

    /**
     * @brief Clears all content from the LCD screen.
     */
    void clear();

    /**
     * @brief Prints a message on the LCD at the specified line and column.
     *
     * @param message The message to be printed on the LCD.
     * @param line The line number (0 or 1) where the message will be printed. Default is 0.
     * @param col The column number where the message will start. Default is 0.
     */
    void print(const String &message, int line = 0, int col = 0);

    /**
     * @brief Updates the LCD with two lines of text, clearing the screen first.
     *
     * @param line1 The message to be printed on the first line.
     * @param line2 The message to be printed on the second line. Default is an empty string.
     */
    void update(const String &line1, const String &line2 = "");

    /**
     * @brief Sets the cursor position on the LCD.
     *
     * @param col The column number (0-based).
     * @param row The row number (0-based).
     */
    void setCursor(uint8_t col, uint8_t row);
};

#endif
