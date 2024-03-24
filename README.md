# Smart Home Automation Using LDR Sensor and SPI Protocol

The Smart Home Automation project utilizes an LDR (Light Dependent Resistor) sensor and SPI (Serial Peripheral Interface) protocol to automate the control of an LED bulb based on ambient light levels. The system consists of an LPC2129 microcontroller, an 8051 microcontroller, an LDR sensor on the 8051 board, and an MCP3204 ADC (Analog-to-Digital Converter) on the 8051 board connected to the LPC2129 microcontroller through SPI communication.

## Components Used

- LPC2129 microcontroller
- 8051 microcontroller
- LDR sensor
- MCP3204 ADC
- LED bulb
- Automation indicator LED
- Switches

## Functionality

- **Automation System:** The system is activated/deactivated using a switch. When the system is turned on, an LED indicator turns on.
- **Ambient Light Sensing:** The LDR sensor measures ambient light levels. If the light level is below 50%, indicating darkness, the LED bulb is turned on.
- **SPI Communication:** The LPC2129 microcontroller communicates with the MCP3204 ADC via SPI to read the analog signal from the LDR sensor.
- **Manual Mode:** Users have the option to override the automatic control and manually control the LED bulb using a separate switch.

