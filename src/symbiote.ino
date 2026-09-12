#include <Adafruit_GFX.h> // graphic basic functions for the display
#include <Adafruit_SSD1306.h> // driver for the SSD1306 OLED-Display

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1); //Display object 128x64, I2C, no reset-pin

const int buttonUp = 22; // GPIO22 = the up botton (HackBat 1.0 schematics)

void setup() {
  // setting I2C Pins (SDA/SCL see HackBat 1.0 schematics)
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();
  delay(250);

  pinMode(buttonUp, INPUT); // Button pin as entrance configuration

  // initialize display 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  delay(100);

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  int state = digitalRead(buttonUp); // read button state: HIGH = pressed, LOW released
  display.clearDisplay();
  display.setCursor(0, 0);

  // shows you text depending on button state
  if (state==HIGH) {
    display.println("Up pressed!");
  } else {
    display.println("Waiting...");
  }

  display.display();
  delay(100);
}
