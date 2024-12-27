/**
 * @file Menu.h
 * @brief Defines the Menu class for creating a navigable menu system on an LCD display.
 */

#ifndef MENU_H
#define MENU_H

#include "LCDController.h"
#include "SimpleVector.h"

/**
 * @class Menu
 * @brief Represents a navigable menu system for an LCD display.
 */
class Menu
{
private:
    LCDController &lcd;              ///< Reference to the LCD controller for displaying the menu.
    SimpleVector<String> &menuItems; ///< Reference to the list of menu items.
    int menuLength;                  ///< Number of items in the menu.
    int currentIndex;                ///< Index of the currently selected menu item.
    Menu *subMenu;                   ///< Pointer to the submenu (if any).
    Menu *parentMenu;                ///< Pointer to the parent menu (if any).

public:
    /**
     * @brief Constructor: Initializes the menu with an LCD controller and a list of menu items.
     * @param lcdController Reference to the LCD controller.
     * @param items Reference to the list of menu items.
     */
    Menu(LCDController &lcdController, SimpleVector<String> &items);

    /**
     * @brief Sets a submenu for the current menu and links it as a child.
     * @param subMenu Pointer to the submenu.
     */
    void setSubMenu(Menu *subMenu);

    /**
     * @brief Sets a parent menu for the current menu and links it as a parent.
     * @param parentMenu Pointer to the parent menu.
     */
    void setParentMenu(Menu *parentMenu);

    /**
     * @brief Displays the current menu items on the LCD screen.
     */
    void show();

    /**
     * @brief Moves the selection to the next menu item.
     */
    void next();

    /**
     * @brief Moves the selection to the previous menu item.
     */
    void previous();

    /**
     * @brief Selects the currently highlighted menu item and navigates to the submenu (if available).
     * @return Pointer to the submenu if available, otherwise nullptr.
     */
    Menu *select();

    /**
     * @brief Navigates back to the parent menu (if available).
     * @return Pointer to the parent menu if available, otherwise nullptr.
     */
    Menu *back();
};

#endif // MENU_H
