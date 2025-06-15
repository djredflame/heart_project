#include <Arduino.h>
#include "LCDController.h"
#include "Menu.h"
#include "SimpleVector.h"

// LCD pin configuration
#define RS 16
#define EN 15
#define D4 7
#define D5 6
#define D6 5
#define D7 4

// Button pin assignments
#define BTN_NEXT 14
#define BTN_PREVIOUS 11
#define BTN_SELECT 13
#define BTN_BACK 12

// Debounce settings
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 300; // 300ms debounce delay

// LCD controller and menu structure
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
  Serial.begin(115200);
  Serial.println("Starting setup...");

  lcd.init();
  lcd.clear();

  // Populate main menu
  mainMenuItems.push_back("Option 1");
  mainMenuItems.push_back("Option 2");
  mainMenuItems.push_back("Option 3");

  // Populate sub menu
  subMenuItems.push_back("Sub-Option 1");
  subMenuItems.push_back("Sub-Option 2");

  // Populate sub-sub menu
  subSubMenuItems.push_back("Sub-Sub-1");

  // Define menu hierarchy using per-entry submenus
  mainMenu.setSubMenu(0, &subMenu);   // Attach Submenu to Option 1 (index 0)
  subMenu.setSubMenu(1, &subSubMenu); // Attach Sub-Submenu to Sub-Option 2 (index 1)

  currentMenu = &mainMenu;

  // Set up button pins with internal pull-up resistors
  pinMode(BTN_NEXT, INPUT_PULLUP);
  pinMode(BTN_PREVIOUS, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BTN_BACK, INPUT_PULLUP);

  currentMenu->show();
}

void loop()
{
  static bool lastSelectState = HIGH;
  static bool lastBackState = HIGH;
  static bool lastNextState = HIGH;
  static bool lastPreviousState = HIGH;

  unsigned long currentMillis = millis();

  bool selectState = digitalRead(BTN_SELECT);
  bool backState = digitalRead(BTN_BACK);
  bool nextState = digitalRead(BTN_NEXT);
  bool previousState = digitalRead(BTN_PREVIOUS);

  if (selectState == LOW && lastSelectState == HIGH && currentMillis - lastDebounceTime > debounceDelay)
  {
    Serial.println("SELECT button pressed");
    Menu *nextMenu = currentMenu->select();
    if (nextMenu != currentMenu)
    {
      currentMenu = nextMenu;
      currentMenu->show();
    }
    lastDebounceTime = currentMillis;
  }
  else if (backState == LOW && lastBackState == HIGH && currentMillis - lastDebounceTime > debounceDelay)
  {
    Serial.println("BACK button pressed");
    Menu *parentMenu = currentMenu->back();
    if (parentMenu != currentMenu)
    {
      currentMenu = parentMenu;
      currentMenu->show();
    }
    lastDebounceTime = currentMillis;
  }
  else if (nextState == LOW && lastNextState == HIGH && currentMillis - lastDebounceTime > debounceDelay)
  {
    Serial.println("NEXT button pressed");
    currentMenu->next();
    lastDebounceTime = currentMillis;
  }
  else if (previousState == LOW && lastPreviousState == HIGH && currentMillis - lastDebounceTime > debounceDelay)
  {
    Serial.println("PREVIOUS button pressed");
    currentMenu->previous();
    lastDebounceTime = currentMillis;
  }

  lastSelectState = selectState;
  lastBackState = backState;
  lastNextState = nextState;
  lastPreviousState = previousState;
}
