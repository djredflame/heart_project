
/**
 * @file LCDController.cpp
 * @brief Implementation of the LCDController class for managing an LCD display using the LiquidCrystal library.
 */

#include "LCDController.h"

/**
 * @brief Constructor for LCDController.
 *
 * Initializes the LCDController with specified pins for the LiquidCrystal library.
 *
 * @param rs Register select pin.
 * @param en Enable pin.
 * @param d4 Data pin 4.
 * @param d5 Data pin 5.
 * @param d6 Data pin 6.
 * @param d7 Data pin 7.
 */
LCDController::LCDController(int rs, int en, int d4, int d5, int d6, int d7)
    : lcd(rs, en, d4, d5, d6, d7) {}

/**
 * @brief Initializes the LCD.
 *
 * Sets up the LCD with 16x2 dimensions and clears the display.
 */
void LCDController::init()
{
    lcd.begin(16, 2);
    lcd.clear();
}

/**
 * @brief Clears the entire LCD display.
 */
void LCDController::clear()
{
    lcd.clear();
}

/**
 * @brief Prints a message on the LCD.
 *
 * Displays a message at the specified line and column on the LCD.
 *
 * @param message The message to be displayed.
 * @param line The line number (0 or 1) where the message will be displayed.
 * @param col The column number where the message will start.
 */
void LCDController::print(const String &message, int line, int col)
{
    lcd.setCursor(col, line);
    lcd.print(message);
}

/**
 * @brief Updates the LCD with two lines of text.
 *
 * Clears the display first, then prints the provided text on the first and second lines.
 *
 * @param line1 The text to be displayed on the first line.
 * @param line2 The text to be displayed on the second line.
 */
void LCDController::update(const String &line1, const String &line2)
{
    clear();
    print(line1, 0, 0);
    print(line2, 1, 0);
}

/**
 * @brief Sets the cursor position on the LCD.
 *
 * @param col The column number (0-based).
 * @param row The row number (0-based).
 */
void LCDController::setCursor(uint8_t col, uint8_t row)
{
    lcd.setCursor(col, row);
}