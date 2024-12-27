/**
 * @file LEDController.h
 * @brief Header file for the LEDController class, which manages multiple LEDs connected to specified pins.
 */

#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>

/**
 * @class LEDController
 * @brief A class to control multiple LEDs connected to specified pins.
 */
class LEDController
{
public:
    /**
     * @brief Constructs an LEDController object.
     *
     * This constructor initializes the LED pins and sets them as OUTPUT.
     *
     * @param pins An array of integers representing the pins to which the LEDs are connected.
     * @param numLeds The number of LEDs connected.
     */
    LEDController(const int *pins, int numLeds);

    /**
     * @brief Blinks all LEDs with a specified delay time.
     *
     * This method turns all LEDs on and off with a delay specified by the user.
     *
     * @param delayTime The delay time in milliseconds between turning the LEDs on and off.
     */
    void blinkAll(int delayTime);

    /**
     * @brief Fades all LEDs in and out with a specified fade time.
     *
     * This method gradually increases and decreases the brightness of all LEDs.
     *
     * @param fadeTime The time in milliseconds for a complete fade in and fade out cycle.
     */
    void fadeAll(int fadeTime);

private:
    const int *ledPins; ///< Array of integers representing the LED pins.
    int numberOfLeds;   ///< The number of LEDs connected.
};

#endif // LEDCONTROLLER_H