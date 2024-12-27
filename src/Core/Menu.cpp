#include "Menu.h"

// Constructor: Initializes the menu with a reference to an LCD controller and a list of items
Menu::Menu(LCDController &lcdController, SimpleVector<String> &items)
    : lcd(lcdController), menuItems(items), currentIndex(0), subMenu(nullptr), parentMenu(nullptr) {}

// Sets the submenu for this menu and establishes a parent-child relationship
void Menu::setSubMenu(Menu *submenu)
{
    subMenu = submenu;
    if (submenu != nullptr)
    {
        submenu->setParentMenu(this);
    }
}

// Sets the parent menu for this menu
void Menu::setParentMenu(Menu *parent)
{
    parentMenu = parent;
}

// Displays the current menu items on the LCD
void Menu::show()
{
    lcd.clear();
    menuLength = menuItems.getSize();
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
void Menu::next()
{
    if (menuLength > 0)
    {
        currentIndex = (currentIndex + 1) % menuLength;
    }
    show();
}

// Moves to the previous menu item
void Menu::previous()
{
    if (menuLength > 0)
    {
        currentIndex = (currentIndex - 1 + menuLength) % menuLength;
    }
    show();
}

// Selects the current menu item and returns the submenu if available
Menu *Menu::select()
{
    return (subMenu != nullptr) ? subMenu : this;
}

// Goes back to the parent menu if available
Menu *Menu::back()
{
    return (parentMenu != nullptr) ? parentMenu : this;
}
