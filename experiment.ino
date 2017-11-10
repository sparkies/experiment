/*
 Name:		experiment.ino
 Created:	11/8/2017 2:30:56 PM
*/

#include <DHT.h>
#include <Adafruit_SSD1306.h>

const uint8_t DHTPIN = 8;
const uint8_t DHTTYPE = DHT11;

const uint8_t OLED_RESET = 4;

const uint8_t OUTPUT_RED = 2;
const uint8_t OUTPUT_GREEN = 3;
const uint8_t OUTPUT_BLUE = 4;

const uint8_t STATUS_BLUE = 11;
const uint8_t STATUS_RED = 12;
const uint8_t STATUS_GREEN = 13;

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(OLED_RESET);

const PROGMEM uint8_t boo_logo[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x0F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x0F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xC0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x0C, 0x00, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x0C, 0x00, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x0C, 0x00, 0x0C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x0C, 0x00, 0x0C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x0C, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x0C, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x03,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x0C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x0C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0xFF, 0x0C, 0x33,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0xFF, 0x0C, 0x33,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x0C, 0x33,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x0C, 0x33,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xCC,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x03, 0xCC,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x0C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x0C,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0xF0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x0F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x0F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x00
};

// the setup function runs once when you press reset or power the board
void setup() {
  //  Start serial port
  Serial.begin(9600);

  //  Start DHT11 temperature sensor
  dht.begin();

  //  Start SSD1306 display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  //  Set default text for display
  display.setTextSize(1);
  display.setTextColor(WHITE);

  //  Set up pins for status and output LEDs
  pinMode(STATUS_RED, OUTPUT);
  pinMode(STATUS_GREEN, OUTPUT);
  pinMode(STATUS_BLUE, OUTPUT);
  pinMode(OUTPUT_RED, OUTPUT);
  pinMode(OUTPUT_GREEN, OUTPUT);
  pinMode(OUTPUT_BLUE, OUTPUT);

  //  Show some logo thing for a few seconds on startup
  display.clearDisplay();
  display.drawBitmap(0, 0, boo_logo, 128, 32, WHITE);
  display.display();
  delay(1);
  display.startscrollleft(0, 15);
  delay(3000);
  display.stopscroll();
}

// the loop function runs over and over again until power down or reset
void loop() {
  //  Read the temp/humidity data from the DHT11 module
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  //  Clear display every iteration
  display.clearDisplay();

  //  Write the uptime near the bottom of the screen.
  display.setCursor(0, 24);
  display.print("Uptime (s): ");
  display.print(millis() / 1000);

  display.setCursor(0, 0);

  if (isnan(temp) || isnan(humidity)) {
    display.println("Could not get data.");

    //  Blink red light on status and output to show error
    if ((millis() / 1000) % 2) {
      set_status_color(255, 0, 0);
      set_output_color(255, 0, 0);
    } 
    else {
      set_status_color(0, 0, 0);
      set_output_color(0, 0, 0);
    }
  }
  else {
    set_status_color(0, 150, 0);
    display.print("Temperature : ");
    display.print((short)temp);
    display.println(" C");
    display.print("Humidity: ");
    display.print((short)humidity);
    display.println(" ");

    if (humidity > 50) {
      set_output_color(255, 0, 0);
    }
    else {
      set_output_color(0, 0, 255);
    }
  }

  display.display();
  delay(50);
}

/// Write RGB values to the tri-color status LED
/// Parameters:
///   r - Red intensity
///   g - Green intensity
///   b - Blue intensity
void set_status_color(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(STATUS_RED, r);
  analogWrite(STATUS_GREEN, g);
  analogWrite(STATUS_BLUE, b);
}

/// Write RGB values to the tri-color output LED
/// Parameters:
///   r - Red intensity
///   g - Green intensity
///   b - Blue intensity
void set_output_color(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(OUTPUT_RED, r);
  analogWrite(OUTPUT_GREEN, g);
  analogWrite(OUTPUT_BLUE, b);
}