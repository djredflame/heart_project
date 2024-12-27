#include <Arduino.h>
#include "LCDController.h"
#include "Menu.h"
#include "SimpleVector.h"

// LCD Pins
#define RS 12
#define EN 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

// Button Pins
#define BTN_NEXT 8
#define BTN_PREVIOUS 9
#define BTN_SELECT 7
#define BTN_BACK 6

// Debounce configuration
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 300; // 300ms debounce delay

// LCD Controller and Menu setup
LCDController lcd(RS, EN, D4, D5, D6, D7);
SimpleVector<String> mainMenuItems;
SimpleVector<String> subMenuItems;
SimpleVector<String> subSubMenuItems;

Menu mainMenu(lcd, mainMenuItems);
Menu subMenu(lcd, subMenuItems);
Menu subSubMenu(lcd, subSubMenuItems);
Menu *currentMenu = &mainMenu;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting setup...");

  lcd.init();
  lcd.clear();

  // Add items to the main menu
  mainMenuItems.push_back("Option 1");
  mainMenuItems.push_back("Option 2");
  mainMenuItems.push_back("Option 3");

  // Add items to the sub menu
  subMenuItems.push_back("Sub-Option 1");
  subMenuItems.push_back("Sub-Option 2");

  // Add items to the sub-sub menu
  subSubMenuItems.push_back("Sub-Sub-1");

 // Set up menu hierarchy
  subMenu.setSubMenu(&subSubMenu);
  mainMenu.setSubMenu(&subMenu);

  currentMenu = &mainMenu;

  // Configure buttons as inputs with pull-up resistors
  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_PREVIOUS, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BTN_BACK, INPUT_PULLUP);

  currentMenu->show();
  Serial.println("Initial menu displayed");
}

void loop()
{
  unsigned long currentMillis = millis();

  // Check "Next" button
  if (digitalRead(BTN_NEXT) == LOW && (currentMillis - lastDebounceTime > debounceDelay))
  {
    currentMenu->next();
    lastDebounceTime = currentMillis;
  }

  // Check "Previous" button
  if (digitalRead(BTN_PREVIOUS) == LOW && (currentMillis - lastDebounceTime > debounceDelay))
  {
    currentMenu->previous();
    lastDebounceTime = currentMillis;
  }

  // Check "Select" button
  if (digitalRead(BTN_SELECT) == LOW && (currentMillis - lastDebounceTime > debounceDelay))
  {
    Menu *nextMenu = currentMenu->select();
    if (nextMenu != currentMenu)
    {
      currentMenu = nextMenu;
    }
    lastDebounceTime = currentMillis;
  }

  // Check "Back" button
  if (digitalRead(BTN_BACK) == LOW && (currentMillis - lastDebounceTime > debounceDelay))
  {
    Menu *parentMenu = currentMenu->back();
    if (parentMenu != currentMenu)
    {
      currentMenu = parentMenu;
    }
    lastDebounceTime = currentMillis;
  }
}
