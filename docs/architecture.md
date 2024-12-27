# **Project Architecture** 🏗️

This document provides an overview of the architecture for the HEARTPROJECT, detailing its structure, components, and interactions.

---

## **Overview** 🌟

The HEARTPROJECT is designed as a modular system with clear separation of concerns. Each component is responsible for a specific functionality, ensuring scalability, maintainability, and ease of integration. The project uses a combination of hardware interaction modules, core logic, and utility classes.

---

## **Core Components** 🔧

### **1. LCD Controller (`LCDController`)** ⚙️

- **Purpose:**
  - Manages the 16x2 LCD display, including initialization, clearing, and displaying text.
- **Key Features:**
  - Clear API for controlling the display.
  - Supports multi-line text updates.
- **File Locations:**
  - Header: `include/LCDController.h`
  - Implementation: `src/Controller/LCDController.cpp`

### **2. Menu System (`Menu`)** 📋

- **Purpose:**
  - Implements a dynamic menu system for the LCD, supporting nested menus and navigation.
- **Key Features:**
  - Submenu and parent menu linkage.
  - Button-driven navigation (Next, Previous, Select, Back).
- **File Locations:**
  - Header: `include/Menu.h`
  - Implementation: `src/core/Menu.cpp`

### **3. Utility Classes (`SimpleVector`)** 🛠️

- **Purpose:**
  - Provides a lightweight dynamic array for managing menu items and other data.
- **Key Features:**
  - Dynamic memory allocation.
  - Simple and efficient API.
- **File Locations:**
  - Header: `include/SimpleVector.h`
  - Implementation: `src/core/SimpleVector.cpp`

### **4. Future Component: LED Controller (`LEDController`)** 💡

- **Purpose:**
  - To control LED animations and patterns.
- **Planned Features:**
  - Advanced LED effects.
  - Support for multiple LEDs and customizable patterns.
- **File Locations (Future):**
  - Header: `include/LEDController.h`
  - Implementation: `src/core/LEDController.cpp`

---

## **Interactions** 🔄

### **1. Hardware Interaction**

- **LCDController:** Directly interfaces with the 16x2 LCD display to manage content.
- **LEDController:** (Planned) Will interface with LEDs for creating animations.

### **2. Core Logic**

- **Menu System:**
  - Uses `LCDController` to render menus on the display.
  - Utilizes `SimpleVector` for dynamic menu item management.

### **3. User Inputs**

- Buttons (connected to digital pins):
  - **Next:** Navigate to the next menu item.
  - **Previous:** Navigate to the previous menu item.
  - **Select:** Enter a submenu or select an option.
  - **Back:** Return to the parent menu.

---

## **Architecture Diagram** 🖼️

```
+-------------------------+
|       User Input        |
| (Buttons: Next, Back)   |
+-------------------------+
             |
             v
+-------------------------+
|      Menu System        |
|  (Core Navigation Logic) |
+-------------------------+
             |
             v
+-------------------------+
|     LCD Controller      |
| (Hardware Interaction)  |
+-------------------------+
             |
             v
+-------------------------+
|        LCD Display       |
|     (16x2 Character)     |
+-------------------------+
```

---

## **Future Enhancements** 🔮

### **1. Infrared Control** 📡

- **Description:** Enable menu navigation via an IR remote.
- **Purpose:** Expand input options for users.

### **2. Ultrasonic Sensor Integration** 📏

- **Description:** Use ultrasonic sensors for distance-based interactions.
- **Purpose:** Add a novel way to interact with the system.

### **3. Bluetooth Communication** 📶

- **Description:** Enable Bluetooth-based interaction for remote control.
- **Purpose:** Facilitate remote monitoring and updates.

### **4. Mobile App Integration** 📱

- **Description:** Control and visualize the system via a mobile app.
- **Purpose:** Improve user experience and accessibility.

---

## **Resources** 📚

- [PlatformIO Documentation](https://docs.platformio.org/)
- [Arduino Reference](https://www.arduino.cc/reference/en/)
- [LiquidCrystal Library](https://www.arduino.cc/en/Reference/LiquidCrystal)

---

This architecture was designed with assistance from ChatGPT 🤖 to ensure scalability and clarity for future development.
