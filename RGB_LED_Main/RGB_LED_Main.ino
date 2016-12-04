#include <Adafruit_NeoPixel.h>


#define PIN 4
#define LED_COUNT 240

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  strip.begin();
  strip.setBrightness(25);
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {
  // turn them on for some color pattern
  everyN(0, 2, 255, 0, 0);
  everyN(1, 2, 0, 255, 0);
  everyN(4, 5, 0, 0, 255);
  strip.show(); // Push the updates to the strip
  delay(random(500, 1000));
  // Turn them off
  everyN(0, 1, 0, 0, 0);
  strip.show();
  delay(random(500, 1000));
  // singleChase();
}

void everyN(byte start, byte inc, byte red, byte green, byte blue) {
  for (int i = start; i < LED_COUNT; i += inc) {
    strip.setPixelColor(i, red, green, blue);
  }
}

void singleChase() {
  uint32_t color = 0;
  for (int i = 0; i < LED_COUNT; i++) {
    // Get the color before we change it to blue
    color = strip.getPixelColor(i);
    // Change it to blue
    strip.setPixelColor(i, 0, 0, 255);
    strip.show();
    
    // Wait
    delay(10);

    // Change it back
    strip.setPixelColor(i, color);
  }
}

void halfAndHalf() {

}
