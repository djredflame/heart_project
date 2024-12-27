#include <Arduino.h>

// LEDController class handles multiple LEDs connected to specified pins
/**
 * @brief LEDController class manages multiple LEDs connected to specified pins.
 */
class LEDController
{
public:
    /**
     * @brief Constructor initializes LED pins and sets them as OUTPUT.
     *
     * @param pins Array of LED pins.
     * @param numLeds Number of LEDs.
     */
    LEDController(const int *pins, int numLeds) : ledPins(pins), numberOfLeds(numLeds)
    {
        for (int i = 0; i < numberOfLeds; i++)
        {
            pinMode(ledPins[i], OUTPUT); // Set each LED pin as output
        }
    }

    /**
     * @brief Method to blink all LEDs with a specified delay time.
     *
     * @param delayTime Time in milliseconds to keep LEDs on or off.
     */
    void blinkAll(int delayTime)
    {
        for (int i = 0; i < numberOfLeds; i++)
        {
            digitalWrite(ledPins[i], HIGH); // Turn on each LED
        }
        delay(delayTime); // Wait for the specified delay time
        for (int i = 0; i < numberOfLeds; i++)
        {
            digitalWrite(ledPins[i], LOW); // Turn off each LED
        }
        delay(delayTime); // Wait for the specified delay time
    }

    /**
     * @brief Method to fade all LEDs in and out with a specified fade time.
     *
     * @param fadeTime Time in milliseconds for each step of the fade.
     */
    void fadeAll(int fadeTime)
    {
        for (int brightness = 0; brightness <= 255; brightness++)
        {
            for (int i = 0; i < numberOfLeds; i++)
            {
                analogWrite(ledPins[i], brightness); // Increase brightness of each LED
            }
            delay(fadeTime); // Wait for the specified fade time
        }
        for (int brightness = 255; brightness >= 0; brightness--)
        {
            for (int i = 0; i < numberOfLeds; i++)
            {
                analogWrite(ledPins[i], brightness); // Decrease brightness of each LED
            }
            delay(fadeTime); // Wait for the specified fade time
        }
    }

private:
    const int *ledPins; // Array of LED pins
    int numberOfLeds;   // Number of LEDs
};