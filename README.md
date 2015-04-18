ESP8266 Microwire EEPROM Driver
========

Supports most Microwire EEPROM devices (93-series)

Works with x8/x16 memory array configurations.

Note: The ESP8266 SPI hardware doesn't support 3-wire mode. You must use 4-wire SPI.

List of possible devices:

ST M93C46/56/66/76/86 (Driver is based on datasheet for this)
Microchip 93LC46/56/66
Atmel AT93C46/56/66

Requires my SPI driver: https://github.com/MetalPhreak/ESP8266_SPI_Driver