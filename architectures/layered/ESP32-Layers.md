# Layers used in ESP32 Development

When we build an application for the ESP32 using the **Arduino development framework**, 
we are actually leveraging a stack of software layers underneath our own code. 

Here is how these layers typically look, from lowest (closest to the hardware) to highest 
(where your user application code runs):


## 1. ESP32 Hardware

This is the actual **silicon**: the microprocessor (Tensilica Xtensa cores 
on the ESP32, RISC-V on ESP32-C), memory, peripherals (UART, SPI, Wi-Fi, Bluetooth, 
etc.), and GPIOs.

* All other software layers ultimately communicate with the real hardware 
    registers and peripherals of the SoC (system on a chip).  



## 2. Espressif IoT Development Framework (ESP-IDF)

The ESP-IDF is Espressif’s official, **low-level SDK for programming the ESP32**. 
It is the base software stack that provides **drivers**, **FreeRTOS-based OS components**, 
**Wi-Fi and Bluetooth stacks**, and other core functionalities.

* It provides APIs to configure and control ESP32 peripherals (PWM, I2C, SPI, Wi-Fi, etc.).  
* It includes the FreeRTOS real-time operating system kernel for task scheduling.  
* The ESP-IDF can be used directly for development, but in the Arduino world, it 
    usually works “behind the scenes.”  

## 3. Arduino Core for ESP32

The **Arduino Core for ESP32** is essentially a wrapper or adaptation layer built on 
top of ESP-IDF. It allows Arduino code (with its familiar functions like `setup()`, 
`loop()`, `pinMode()`, `digitalWrite()`, etc.) to run on the ESP32.

* It translates standard Arduino function calls into equivalent ESP-IDF functions.  
* It includes board definitions, pin mappings, default configurations, and initialization 
    routines specific to various ESP32 boards.  
* It keeps the Arduino API consistent with the typical Arduino C++ environment.  


## 4. Arduino Libraries (and Third-Party Libraries)

Libraries such as **WiFiClient**, **SPIFFS/LittleFS**, **Ethernet**, **Bluetooth**, 
**HTTPClient**, **MQTT**, etc., provide ready-made modules to handle common functionalities.

* Many of these libraries are adapted to use ESP-IDF features under the hood (for example, 
    WiFiClient is built on top of ESP-IDF’s Wi-Fi and TCP/IP stack).  
* The Arduino ecosystem includes both official and community-contributed libraries, all 
    of which ultimately rely on the Arduino Core and ESP-IDF.  


## 5. User Application Code

This is your sketch (.ino file) or your C++ source code, which you write in the Arduino 
IDE (or other environments like PlatformIO).  

In standard Arduino style, we implement a `setup()` function (runs once) and a `loop()` 
function (runs repeatedly).

* Our code directly calls Arduino API functions (e.g., `pinMode()`, `digitalWrite()`, 
    `WiFi.begin()`, etc.).  
* At compile time, our code is linked with the Arduino libraries, which themselves 
    rely on ESP-IDF.  
* Once compiled and uploaded, our application code runs on the ESP32 hardware.  


This layered architecture lets us write simple Arduino-style sketches, while under 
the hood it benefits from the robust and feature-rich platform provided by the ESP-IDF.


## References

* [Arduino core for the ESP32, ESP32-P4, ESP32-S2, ESP32-S3, ESP32-C3, ESP32-C6 and ESP32-H2](https://github.com/espressif/arduino-esp32)

* [ESP32 Arduino Core’s documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

*Egon Teiniker, 2020-2025, GPL v3.0*