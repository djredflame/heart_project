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

#define ONBOARD_LED LED_BUILTIN

// Debounce settings
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 300; // 300ms debounce delay

// LCD controller and menu structure
LCDController lcd(RS, EN, D4, D5, D6, D7);
// Global SimpleVector declarations removed; now defined inside buildMenuTree()

Menu *currentMenu = nullptr;

Menu *buildMenuTree()
{
  // Menu item vectors
  static SimpleVector<String> itemsMain;
  static SimpleVector<String> itemsLedControl;
  static SimpleVector<String> itemsLedOnOff;

  if (itemsMain.size() == 0)
  {
    itemsMain.push_back("LED Control");
    itemsMain.push_back("Games");
    itemsMain.push_back("Settings");

    itemsLedControl.push_back("On-Off");
    itemsLedControl.push_back("Draw");

    itemsLedOnOff.push_back("All LEDs On");
    itemsLedOnOff.push_back("All LEDs Off");
  }

  // Menu objects
  static Menu menuMain(lcd, itemsMain);
  static Menu menuLedControl(lcd, itemsLedControl);
  static Menu menuLedOnOff(lcd, itemsLedOnOff);

  // Link submenus to their parent items
  menuMain.setSubMenu(0, &menuLedControl);     // LED Control
  menuLedControl.setSubMenu(0, &menuLedOnOff); // On-Off

  return &menuMain;
}

void setup()
{
  Serial.begin(115200);
  pinMode(ONBOARD_LED, OUTPUT);
  Serial.println("Starting setup...");

  lcd.init();
  lcd.clear();

  // Legacy menu setup removed in favor of buildMenuTree()

  currentMenu = buildMenuTree();

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
    // Save pointer to menu before selection to determine which menu we were in
    Menu *previousMenu = currentMenu;
    Menu *nextMenu = currentMenu->select();
    currentMenu = nextMenu;

    // Only toggle LED when user selects a terminal action item in the LED On-Off menu
    // The LED On-Off menu contains "All LEDs On" and "All LEDs Off"
    // So, if previousMenu's current item is one of those, handle LED
    String selectedItem = previousMenu->getItem(previousMenu->getCurrentIndex());
    if (selectedItem == "All LEDs On")
    {
      digitalWrite(ONBOARD_LED, HIGH);
      Serial.println("LED turned ON");
    }
    else if (selectedItem == "All LEDs Off")
    {
      digitalWrite(ONBOARD_LED, LOW);
      Serial.println("LED turned OFF");
    }

    currentMenu->show();
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
