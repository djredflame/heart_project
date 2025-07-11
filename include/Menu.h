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
    int startIndex;                  ///< Index of the first menu item currently displayed (for scrolling).
    SimpleVector<Menu *> subMenus;   ///< Vector of pointers to submenus.
    Menu *parentMenu;                ///< Pointer to the parent menu (if any).

public:
    /**
     * @brief Constructor: Initializes the menu with an LCD controller and a list of menu items.
     * @param lcdController Reference to the LCD controller.
     * @param items Reference to the list of menu items.
     */
    Menu(LCDController &lcdController, SimpleVector<String> &items);

    /**
     * @brief Sets a submenu for the current menu at the given index and links it as a child.
     * @param index Index of the menu item to associate with the submenu.
     * @param subMenu Pointer to the submenu.
     */
    void setSubMenu(int index, Menu *subMenu);

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

    /**
     * @brief Returns the index of the currently selected menu item.
     * @return The current index.
     */
    int getCurrentIndex() const;

    /**
     * @brief Returns the menu item at a given index.
     * @param index Index of the item to retrieve.
     * @return The menu item string.
     */
    String getItem(int index) const;
};

#endif // MENU_H
