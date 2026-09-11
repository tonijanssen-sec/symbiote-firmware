## Toolchain


- Arduiono IDE 2.3.10
- RP2040 Board Package (earlephilhower/arduino-pico) 6.1.0
- Board: Raspberry Pi Pico
- Boards Manager Url: https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json

## Display
- Datasheet specifies SH1106, but the actual chip on this unit is **SSD1306**
- Library: Adafruit SSD1306 (not SH110X!)
- I2C address: 0x3C
- Pins: SDA = GPI04, SCL = GPI05
