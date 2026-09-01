# Automated Greenhouse Climate Control System

A bare-metal embedded C project designed to regulate a greenhouse environment using an ATmega32 microcontroller. This system implements a robust, priority-based hierarchical state machine to manage automatic climate control, manual hardware overrides, dynamic threshold configurations, and safety-critical emergency lock-outs.

## Hardware Architecture
*   **Microcontroller:** AVR ATmega32 (8MHz)
*   **Sensors:** DHT22 (Temperature & Humidity)
*   **User Interface:** 16x2 Character LCD (HD44780) & 4x3 Matrix Keypad
*   **Actuators (Relay-Driven):** Heating Element, Ventilation Fan, Water Pump
*   **Manual Inputs:** External Interrupt (EXTI) button for mode switching, dedicated push buttons for manual relay toggling.
*   **Indicators:** Dedicated LEDs for Heating, Ventilation, and Watering emergency states.

## Software Architecture
The firmware is written in standard C99 and strictly follows a layered architecture, separating the application logic from the hardware dependencies through custom **MCAL** (Microcontroller Abstraction Layer) and **HAL** (Hardware Abstraction Layer) drivers. 

To maintain system responsiveness without RTOS overhead, the architecture utilizes non-blocking timer logic and modular state polling rather than blocking `while(1)` delay loops.

### Master State Machine
The system logic is governed by a flat, priority-based state machine that ensures safety limits are evaluated before any user inputs or control routines are executed.

| System State | Description | Priority |
| :--- | :--- | :--- |
| `EMERGENCY_STATE` | **Highest.** Triggered automatically if fatal temperature or humidity thresholds are breached. Locks out the LCD and keypad, disables all standard actuators, and activates warning LEDs until the environment stabilizes. | 1 |
| `CONFIG_STATE` | **High.** Accessed via the 'C' key. A sub-state machine that pauses active control to allow multi-digit integer entry via the keypad. Updates dynamic parameters (`Max_Temp`, `Min_Temp`, `Min_Moist`) in memory. | 2 |
| `CONTROL_STATE` | **Standard.** The default operating mode. Routes execution to either `Automatic_Mode` or `Manual_Mode` based on the EXTI toggle switch. | 3 |

### Control Sub-Modes
*   **Automatic Mode:** Continuously evaluates DHT22 sensor data against user-defined configurations. Employs deadband logic to toggle the fan (cooling) or heater (warming), ensuring both cannot run simultaneously. The water pump operates independently based on soil moisture minimums.
*   **Manual Mode:** Disables automatic sensor responses, giving the user direct push-button control over the relays. Incorporates debounced toggle logic and hardware interlocks (e.g., preventing heater engagement while the fan is active).

## Keypad Pin Mapping
The matrix keypad is designed to span multiple ports using array-based pin mapping to bypass hardware conflicts (such as reserved Timer0 or JTAG pins). 

*   **Rows (0-3):** PB3, PB4, PB5, PB6
*   **Cols (0-2):** PD0, PD1, PD3

## Development Environment
*   **Toolchain:** AVR-GCC Toolchain
*   **Simulation:** Proteus ISIS
*   **Language:** C (Bare-metal)

---
**Author:** 
Zeyad Hany 
Computer Engineering, The British University in Egypt (BUE)
