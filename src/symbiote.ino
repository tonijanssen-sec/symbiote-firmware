#include <Adafruit_GFX.h> // graphic basic functions for the display
#include <Adafruit_SSD1306.h> // driver for the SSD1306 OLED-Display

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1); //Display object 128x64, I2C, no reset-pin

const int buttonUp = 22; // GPIO22 = the up botton (HackBat 1.0 schematics)
const int buttonLeft = 26;
const int buttonEnter = 27;
const int buttonRight = 28;
const int buttonDown = 29;

const char* menuItems[]{"Scanner", "Settings", "About"}; // menu list
const int menuLength = 3; 
int selectedIndex = 0; // which item is currently selected 

void setup() {
  // setting I2C Pins (SDA/SCL see HackBat 1.0 schematics)
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();
  delay(250);

  pinMode(buttonUp, INPUT); // Button pin as entrance configuration
  pinMode(buttonLeft, INPUT);
  pinMode(buttonEnter, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(buttonDown, INPUT);

  // initialize display 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  delay(100);

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  int stateUp = digitalRead(buttonUp); // read button state: HIGH = pressed, LOW released
  int stateLeft = digitalRead(buttonLeft);
  int stateEnter = digitalRead(buttonEnter);
  int stateRight = digitalRead(buttonRight);
  int stateDown = digitalRead(buttonDown);

  if (stateUp == HIGH) {
    selectedIndex--; // move cursor up
    if (selectedIndex < 0) selectedIndex = menuLength - 1; // wrap to bottom (basically goes from index 0 to last item, index 2 = About)
    delay(200); // simple delay so it doesn't scroll too fast
  }

  if (stateDown == HIGH) {
    selectedIndex++; // move cursor down
    if (selectedIndex >= menuLength) selectedIndex = 0; // wrap to top (same logic as stateUp, just reversed)
    delay(200);
  }

  display.clearDisplay();
  for (int i = 0; i < menuLength; i++) {
    display.setCursor(0, i * 10); // column distance so the items don't overlap in the menu, 0=0, 1=10, 2=20
    if (i == selectedIndex) {
      display.print("> "); // draw arrow if this line is the selected one
    } else {
      display.print("  "); // otherwise draw blank space so text keeps aligned
    }
    display.println(menuItems[i]);
  }
  display.display();
}
