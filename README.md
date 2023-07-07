# Using MCP9808 with Arduino R4 Minima (RA4M1 Renesas Cortex-M4 Core).

## Project Description

This project is implementing a simple example to test I2C interface on R4 Minima. The example uses Wire.h library to communicate through I2C with the sensor
(MCP9808) and read temperature data. Also SoftwareSerial.h is used to print data on the Serial Monitor. For this purpose a USB to UART converter is used (CP210x Silicon Labs).

## Hardware Connections
**Sensor MCP9808**
>- 3.3 V -> 3.3 V
>- SDA->SDA
>- SCL->SCL
>- GND->GND
 
**CP210x USB to UART Converter (CP2102N Silicon Labs)**

In the code as TX and RX pins are defined:
```cpp
#define RX_PIN 10
#define TX_PIN 11
```

>- TX (Arduino) -> RX (CP2102N)
>- RX (Arduino) -> TX (CP2102N)
>- Common GND.

## Components
[Arduino R4 Minima](https://store.arduino.cc/pages/uno-r4)

[MCP9808](https://www.mikroe.com/thermo-8-click)

[CP2102N Silicon Labs](https://www.silabs.com/development-tools/interface/cp2102n-mini-development-kit?tab=overview)

