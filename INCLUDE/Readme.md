# STM32 IR Controlled Calculator

A full-function calculator project implemented on STM32 microcontroller, controlled via an Infrared (IR) remote, and displaying results on a TFT display.  
This repository includes drivers, application code, and math utilities required to run the project.

---

## **Features**
- Full arithmetic operations and additional math functions (factorial, etc.)
- IR remote control input handled via NVIC interrupt
- TFT display output with graphical user interface
- SPI communication for TFT screen
- Modular and layered embedded software structure

---

## **Included Header Files**

### **System Core**
- **BIT_MATH.h** – Common bit manipulation macros.
- **STD_TYPES.h** – Standard data types (u8, u16, s32, etc.).

### **MCU Peripheral Drivers**
- **MRCC_interface.h** – Clock configuration and peripheral enable functions.
- **MGPIO_interface.h** – GPIO configuration and control functions.
- **MSYSTICK_interface.h** – SysTick timer configuration and delays.
- **MNVIC_interface.h** – Nested Vector Interrupt Controller (NVIC) driver.
- **MEXTI_interface.h** – External interrupts (EXTI) configuration.

### **Communication & Display**
- **MSPI_interface.h** – SPI driver used for TFT communication.
- **TFT_interface.h** – TFT display driver (drawing, colors, cursor control).

### **Application Level**
- **IR_interface.h** – IR remote receiver driver and API.
- **CALC.h** – Calculator logic and math operations.
- **TFT_CALC.h** – Graphical interface and display functions for calculator.
- **math_functions.h** – Additional math utilities (factorial, power, etc.).

---

## **How to Build**
1. Import the project into an STM32 IDE (Keil, STM32CubeIDE, or similar).
2. Connect:
   - TFT display via SPI (pins A4-A7 or as configured in code)
   - IR sensor to GPIOB pin 0.
3. Build and flash to the STM32 board.
4. Use an IR remote to interact with the calculator.

---

## **How to Build**
1. Import the project into an STM32 IDE (Keil, STM32CubeIDE, or similar).
2. Connect:
   - TFT display via SPI (pins A4-A7 or as configured in code)
   - IR sensor to GPIOB pin 0.
3. Build and flash to the STM32 board.
4. Use an IR remote to interact with the calculator.

---
