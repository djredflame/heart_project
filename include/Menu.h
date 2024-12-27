#ifndef MENU_H
#define MENU_H

#include "LCDController.h"
#include "SimpleVector.h"

// The Menu class represents a navigable menu system for an LCD display.
class Menu
{
private:
    LCDController &lcd;              // Reference to the LCD controller for displaying the menu
    SimpleVector<String> &menuItems; // Reference to the list of menu items
    int menuLength;                  // Number of items in the menu
    int currentIndex;                // Index of the currently selected menu item
    Menu *subMenu;                   // Pointer to the submenu (if any)
    Menu *parentMenu;                // Pointer to the parent menu (if any)

public:
    // Constructor: Initializes the menu with an LCD controller and a list of menu items
    Menu(LCDController &lcdController, SimpleVector<String> &items);

    // Sets a submenu for the current menu and links it as a child
    void setSubMenu(Menu *subMenu);

    // Sets a parent menu for the current menu and links it as a parent
    void setParentMenu(Menu *parentMenu);

    // Displays the current menu items on the LCD
    void show();

    // Moves the selection to the next menu item
    void next();

    // Moves the selection to the previous menu item
    void previous();

    // Selects the currently highlighted menu item and navigates to the submenu (if available)
    Menu *select();

    // Navigates back to the parent menu (if available)
    Menu *back();
};

#endif
