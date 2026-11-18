# 💧 Smart Automatic Water Tank Management & IoT Monitoring System

An embedded IoT and industrial automation solution built around the **NXP LPC2129 ARM7 Microcontroller**[span_6](start_span)[span_6](end_span)[span_7](start_span)[span_7](end_span). Designed for apartments, campuses, hospitals, and industrial facilities, this system eliminates manual pump supervision, prevents water overflow and dry-running, logs operational history, and provides real-time remote monitoring via the ThingSpeak cloud[span_8](start_span)[span_8](end_span)[span_9](start_span)[span_9](end_span)[span_10](start_span)[span_10](end_span).

---

## 🚀 Key Features

* **Dual-Sensor Level Validation:** Cross-verifies water levels using both an analog **Water Level Sensor** and an **Ultrasonic Distance Sensor** to improve accuracy and detect sensor faults[span_11](start_span)[span_11](end_span)[span_12](start_span)[span_12](end_span).
* **Automated Pump & Valve Control:** Automatically switches the water pump ON/OFF via a **Relay Driver** and regulates water flow using a **PWM-controlled Servo Motor** valve[span_13](start_span)[span_13](end_span)[span_14](start_span)[span_14](end_span).
* **Manual Override Mode:** Physical **User Switches** allow operators to toggle between Automatic and Manual modes during maintenance or emergencies without modifying firmware[span_15](start_span)[span_15](end_span).
* **IoT Cloud Telemetry:** Connects to **ThingSpeak** via an **ESP-01 Wi-Fi Module** (UART) for live remote monitoring of water levels, temperature, pump state, and alerts[span_16](start_span)[span_16](end_span).
* **Dual-Layer Data Storage & Timestamping:**
  * **DS1307 RTC:** Provides accurate date/time stamps for all pump and alarm events[span_17](start_span)[span_17](end_span)[span_18](start_span)[span_18](end_span).
  * **AT24C256 EEPROM:** Retains critical system configurations across power outages[span_19](start_span)[span_19](end_span).
  * **SD Card Module:** Logs long-term historical telemetry (water levels, temperatures, pump runtime) for usage analytics[span_20](start_span)[span_20](end_span).
* **Industrial Multi-Node Scalability:** Integrates an **MCP2551 CAN Transceiver** to network multiple LPC2129 tank controllers across large facilities[span_21](start_span)[span_21](end_span)[span_22](start_span)[span_22](end_span).
* **Local UI & Alerts:** Real-time status readout on a **16×2 LCD**, visual status **LEDs** (Green/Orange/Red), and an audible **Buzzer** for critical warnings[span_23](start_span)[span_23](end_span)[span_24](start_span)[span_24](end_span)[span_25](start_span)[span_25](end_span).

---

## 🛠️ Hardware & Pin Mapping

| Category | Component | Interface / Pin Assignment | Function |
| :--- | :--- | :--- | :--- |
| **MCU** | NXP LPC2129 (ARM7) | 5V DC Regulated Supply | Central processing & peripheral control[span_26](start_span)[span_26](end_span)[span_27](start_span)[span_27](end_span) |
| **Sensors** | Water Level Sensor | `ADC0.0` (`P0.27` / CH0) | Primary analog water level measurement[span_28](start_span)[span_28](end_span)[span_29](start_span)[span_29](end_span)[span_30](start_span)[span_30](end_span) |
| | Ultrasonic Sensor | `ADC0.1` (`P0.28` / CH1) | Non-contact water surface distance measurement[span_31](start_span)[span_31](end_span)[span_32](start_span)[span_32](end_span) |
| | LM35 Temp Sensor | `ADC0.2` (`P0.29` / CH2) | Ambient/water temperature monitoring[span_33](start_span)[span_33](end_span)[span_34](start_span)[span_34](end_span) |
| **Inputs** | User Switches (SW1–SW3) | GPIO (`P0.14`, `P0.15`, `P0.16`) | Manual pump override & mode control[span_35](start_span)[span_35](end_span)[span_36](start_span)[span_36](end_span) |
| **Actuators** | Relay Driver + Pump | GPIO Digital Output | High-voltage AC/DC water pump switching[span_37](start_span)[span_37](end_span)[span_38](start_span)[span_38](end_span) |
| | Servo Motor | PWM Output | Automated water inlet/outlet valve control[span_39](start_span)[span_39](end_span)[span_40](start_span)[span_40](end_span) |
| **Comms & Storage** | ESP-01 Wi-Fi Module | `UART0` | Telemetry upload to ThingSpeak cloud[span_41](start_span)[span_41](end_span)[span_42](start_span)[span_42](end_span) |
| | DS1307 RTC | `I²C` Bus | Real-time clock & event timestamping[span_43](start_span)[span_43](end_span)[span_44](start_span)[span_44](end_span) |
| | AT24C256 EEPROM | `I²C` Bus | Non-volatile configuration storage[span_45](start_span)[span_45](end_span)[span_46](start_span)[span_46](end_span) |
| | SD Card Module | `SPI` Bus | Long-term CSV/text operational logging[span_47](start_span)[span_47](end_span)[span_48](start_span)[span_48](end_span) |
| | MCP2551 Transceiver | `CAN` Interface | Node-to-node industrial communication[span_49](start_span)[span_49](end_span)[span_50](start_span)[span_50](end_span) |
| **Indicators** | 16×2 LCD Display | 4-Bit Parallel Interface | Live local system telemetry display[span_51](start_span)[span_51](end_span)[span_52](start_span)[span_52](end_span) |
| | Status LEDs | GPIO (`P0.17` Red, `P0.18` Orange, `P0.19` Green) | Quick visual state indication[span_53](start_span)[span_53](end_span)[span_54](start_span)[span_54](end_span) |
| | Buzzer | GPIO (`P0.21` Active High) | Audible fault & critical level alarm[span_55](start_span)[span_55](end_span)[span_56](start_span)[span_56](end_span) |

---

## ⚙️ Working Principle

1. **Data Acquisition:** The LPC2129 polls the Water Level Sensor, Ultrasonic Sensor, LM35 Temperature Sensor, User Switches, and DS1307 RTC[span_57](start_span)[span_57](end_span)[span_58](start_span)[span_58](end_span).
2. **Decision & Actuation:** 
   * When water drops below the minimum threshold, the controller energizes the **Relay** (Pump ON) and opens the **Servo Valve**[span_59](start_span)[span_59](end_span)[span_60](start_span)[span_60](end_span).
   * Once the tank reaches 100%, the pump shuts OFF and the valve closes to prevent overflow[span_61](start_span)[span_61](end_span)[span_62](start_span)[span_62](end_span).
3. **Feedback & Logging:** Live metrics are pushed to the **16×2 LCD** and **UART0** serial terminal, logged with RTC timestamps to the **EEPROM** and **SD Card**, and transmitted to **ThingSpeak** via the **ESP-01**[span_63](start_span)[span_63](end_span)[span_64](start_span)[span_64](end_span)[span_65](start_span)[span_65](end_span)[span_66](start_span)[span_66](end_span).

---

## 🖥️ Sample Serial Monitor Output (`UART0`)

```text
SMART WATER TANK MANAGEMENT SYSTEM
Controller     : LPC2129 ARM7
Project Status : RUNNING
Water Level    : 78%
Distance       : 12 cm
Temperature    : 29°C
Pump Status    : OFF
Relay Status   : OFF
Valve Status   : CLOSED
Wi-Fi Status   : CONNECTED
Cloud Status   : UPDATED
RTC Date       : 30/07/2026
RTC Time       : 10:45:30 AM
EEPROM Status  : DATA SAVED
SD Card Status : LOG SAVED
CAN Status     : ACTIVE
System Status  : NORMAL
Monitoring...
