#include "Menu.h"

// Constructor: Initializes the menu with a reference to an LCD controller and a list of items
/**
 * @brief Initializes the menu with a reference to an LCD controller and a list of items.
 *
 * @param lcdController Reference to the LCD controller.
 * @param items List of menu items.
 */
Menu::Menu(LCDController &lcdController, SimpleVector<String> &items)
    : lcd(lcdController), menuItems(items), currentIndex(0), parentMenu(nullptr) {}

// Sets the submenu for this menu and establishes a parent-child relationship
/**
 * @brief Sets the submenu for this menu and establishes a parent-child relationship.
 *
 * @param index Index of the submenu.
 * @param submenu Pointer to the submenu.
 */
void Menu::setSubMenu(int index, Menu *submenu)
{
    if (subMenus.size() <= index)
    {
        while (subMenus.size() <= index)
        {
            subMenus.push_back(nullptr);
        }
    }
    subMenus[index] = submenu;
    if (submenu != nullptr)
    {
        submenu->setParentMenu(this);
    }
}

// Sets the parent menu for this menu
/**
 * @brief Sets the parent menu for this menu.
 *
 * @param parent Pointer to the parent menu.
 */
void Menu::setParentMenu(Menu *parent)
{
    parentMenu = parent;
}

// Displays the current menu items on the LCD
/**
 * @brief Displays the current menu items on the LCD.
 */
void Menu::show()
{
    lcd.clear();
    menuLength = menuItems.size();
    if (menuLength == 0)
    {
        lcd.print("No Items", 0, 0);
        return;
    }

    for (int i = 0; i < menuLength && i < 2; i++) // Display up to 2 items (for 16x2 LCD)
    {
        String item = menuItems[i];
        lcd.print(i == currentIndex ? ">" : " ", i, 0); // Print '>' for the current selection
        lcd.print(item.substring(0, 15), i, 1);         // Print the menu item (limit to 15 characters)
    }
}

// Moves to the next menu item
/**
 * @brief Moves to the next menu item.
 */
void Menu::next()
{
    if (menuLength > 0)
    {
        currentIndex = (currentIndex + 1) % menuLength;
    }
    show();
}

// Moves to the previous menu item
/**
 * @brief Moves to the previous menu item.
 */
void Menu::previous()
{
    if (menuLength > 0)
    {
        currentIndex = (currentIndex - 1 + menuLength) % menuLength;
    }
    show();
}

// Selects the current menu item and returns the submenu if available
/**
 * @brief Selects the current menu item and returns the submenu if available.
 *
 * @return Pointer to the submenu if available, otherwise returns this menu.
 */
Menu *Menu::select()
{
    if (currentIndex < subMenus.size() && subMenus[currentIndex] != nullptr)
    {
        return subMenus[currentIndex];
    }
    return this;
}

// Goes back to the parent menu if available
/**
 * @brief Goes back to the parent menu if available.
 *
 * @return Pointer to the parent menu if available, otherwise returns this menu.
 */
Menu *Menu::back()
{
    return (parentMenu != nullptr) ? parentMenu : this;
}