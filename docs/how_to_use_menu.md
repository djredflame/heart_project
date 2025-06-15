# **How to Use the Menu System** 📋

This guide provides step-by-step instructions on how to navigate and interact with the dynamic menu system of the HEARTPROJECT.

---

## **Overview** 🌟

The menu system is displayed on a 16x2 LCD screen and allows users to navigate through options using buttons. It supports nested menus, parent menu navigation, and dynamic content updates.

---

## **Menu Navigation** 🔄

### **1. Button Functions** 🎮

The system uses four buttons connected to digital pins:

- **Next (Button 11):**

  - Move to the next menu item.
  - Wraps around to the first item after the last.

- **Previous (Button 12):**

  - Move to the previous menu item.
  - Wraps around to the last item before the first.

- **Select (Button 10):**

  - Enter the selected submenu (if available).
  - Executes actions associated with the selected item.

- **Back (Button 9):**
  - Return to the parent menu.
  - If in the main menu, no action is taken.

### **2. Menu Display** 🖥️

- The menu system displays two items at a time on the 16x2 LCD.
- A `>` symbol indicates the currently selected menu item.

---

## **Starting the Menu System** 🚀

1. **Power the Raspberry Pi Pico 2W:**

   - Connect the Pico 2W via USB to a power source (hold BOOTSEL if necessary).

2. **LCD Initialization:**

   - The LCD will initialize and clear any previous content.

3. **Main Menu Display:**
   - The first two items in the main menu will be displayed.
   - Use the **Next** and **Previous** buttons to navigate.

---

## **Navigating Menus** 🧭

### **1. Moving Between Items**

- Use the **Next** button to cycle forward through the menu items.
- Use the **Previous** button to cycle backward through the menu items.

### **2. Entering a Submenu**

- Highlight a menu item with a submenu.
- Press the **Select** button to enter the submenu.
- The submenu items will be displayed.

### **3. Returning to a Parent Menu**

- While in a submenu, press the **Back** button to return to the parent menu.
- If already in the main menu, pressing **Back** has no effect.

---

## **Example Workflow** 🛠️

1. **Starting Point:**

   - The main menu displays:
     ```
     > Option 1
       Option 2
     ```

2. **Navigating:**

   - Press **Next** to move to `Option 2`:
     ```
       Option 1
     > Option 2
     ```

3. **Selecting a Submenu:**

   - If `Option 2` has a submenu, press **Select** to enter:

     ```
     > Sub-Option 1
       Sub-Option 2
     ```

   - Press **Next** to highlight `Sub-Option 2`:

     ```
       Sub-Option 1
     > Sub-Option 2
     ```

   - Press **Select** again to enter the next level submenu:
     ```
     > Sub-Sub-1
     ```

4. **Returning:**
   - Press **Back** to return to the main menu:
     ```
       Option 1
     > Option 2
     ```

---

## **Troubleshooting** 🛠️

### **1. No Display on LCD**

- Ensure the LCD is correctly wired to the Raspberry Pi Pico 2W.
- Verify the `RS`, `EN`, `D4`, `D5`, `D6`, and `D7` pin assignments in the code.
- Check that `LCDController` is initialized in `setup()`.

### **2. Buttons Not Working**

- Confirm the button wiring matches the pin assignments in the code.
- Use `INPUT_PULLUP` mode for reliable button presses.
- Debounce issues can be resolved by adjusting the `delay()` in the loop.

### **3. Menu Not Updating**

- Verify that `currentMenu->show()` is called after navigation.
- Check that menu items are correctly populated in `mainMenuItems`, `subMenuItems`, etc.

---

## **Additional Notes** 📝

- Menus are designed to handle up to two lines of text at a time.
- Menu items longer than 16 characters will be truncated.
- Submenus must be explicitly linked to their parent menus using `setSubMenu()` and `setParentMenu()`.

---

For more details, see the [Project Architecture](./architecture.md).

---

This guide was designed with the assistance of ChatGPT 🤖 to ensure clarity and ease of use for developers and users.
