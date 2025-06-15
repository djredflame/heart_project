#include "Menu.h"

// Constructor: Initializes the menu with a reference to an LCD controller and a list of items
/**
 * @brief Initializes the menu with a reference to an LCD controller and a list of items.
 *
 * @param lcdController Reference to the LCD controller.
 * @param items List of menu items.
 */
Menu::Menu(LCDController &lcdController, SimpleVector<String> &items)
    : lcd(lcdController), menuItems(items), currentIndex(0), parentMenu(nullptr), startIndex(0) {}

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

    int startIndex = 0;
    if (menuLength > 2)
    {
        if (currentIndex == 0)
            startIndex = 0;
        else if (currentIndex == menuLength - 1)
            startIndex = menuLength - 2;
        else
            startIndex = currentIndex - 1;
    }

    for (int i = 0; i < 2; i++)
    {
        int itemIndex = startIndex + i;
        if (itemIndex >= menuLength)
            break;

        lcd.print((itemIndex == currentIndex) ? ">" : " ", i, 0);
        lcd.print(menuItems[itemIndex].substring(0, 15), i, 1);
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

/**
 * @brief Returns the index of the currently selected menu item.
 * @return The current index.
 */
int Menu::getCurrentIndex() const
{
    return currentIndex;
}

/**
 * @brief Returns the menu item at a given index.
 * @param index Index of the item to retrieve.
 * @return The menu item string.
 */
String Menu::getItem(int index) const
{
    return menuItems[index];
}