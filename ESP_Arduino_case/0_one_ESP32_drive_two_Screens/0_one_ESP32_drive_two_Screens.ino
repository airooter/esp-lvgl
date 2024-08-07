#include <Arduino.h>
#include <SPI.h>
#include <Arduino_GFX.h>

// Define display type and connection pins
#define SCREEN_TYPE Arduino_GC9A01 // Choose display type
#define RST_PIN 1 // RST pin for the first display
#define DC_PIN 11 // DC pin for the first display
#define CS_PIN 10 // CS pin for the first display
#define SCK_PIN 12 // SCK pin for the first display
#define MOSI_PIN 13 // MOSI pin for the first display

#define DC_PIN2 41 // DC pin for the second display
#define CS_PIN2 42 // CS pin for the second display
#define SCK_PIN2 39 // SCK pin for the second display
#define MOSI_PIN2 0 // MOSI pin for the second display

// Create data bus objects
Arduino_DataBus *bus = new Arduino_ESP32SPI(DC_PIN, CS_PIN, SCK_PIN, MOSI_PIN, GFX_NOT_DEFINED);
Arduino_DataBus *bus2 = new Arduino_ESP32SPI(DC_PIN2, CS_PIN2, SCK_PIN2, MOSI_PIN2, GFX_NOT_DEFINED);

// Create display objects
SCREEN_TYPE *gfx = new SCREEN_TYPE(bus, RST_PIN, 1, true); // Initialize the first display
SCREEN_TYPE *gfx2 = new SCREEN_TYPE(bus2, GFX_NOT_DEFINED, 0, true); // Initialize the second display

void setup() {
  // Initialize both displays
  gfx->begin();
  gfx2->begin();

  // Set the background color of the first display to black
  gfx->fillScreen(BLACK);

  // Draw a red rectangle on the second display
  gfx2->fillRect(10, 10, 50, 50, RED);
}

void loop() {
  // No loop needed
}