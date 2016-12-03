// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define REDPIN 9
#define GREENPIN 10
#define BLUEPIN 11
#define MAX_BRIGHTNESS 100

#define FADESPEED 100     // make this higher to slow down

// Function declarations
void colorFade(byte fromColor, byte toColor, byte delayMS = FADESPEED, byte minBrightness = 0, byte maxBrightness = 255);
void fadeOut(byte color, byte delayMS = FADESPEED, byte minBrightness = 0, byte maxBrightness = 255);
void fadeIn(byte color, byte delayMS = FADESPEED, byte minBrightness = 0, byte maxBrightness = 255);


void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

}


void loop() {
  //  colorFade(REDPIN, GREENPIN);
  //  colorFade(GREENPIN, REDPIN);
  fadeOut(REDPIN, 100, 0, 25);
  fadeIn(GREENPIN, 5, 0, 25);
  fadeOut(GREENPIN, 5, 0, 25);
  fadeIn(REDPIN, 100, 0, 25);
}

void colorFade(byte fromColor, byte toColor, byte delayMS = FADESPEED, byte minBrightness = 0, byte maxBrightness = 255) {
  for (int i = minBrightness; i <= maxBrightness; i++) {
    analogWrite(fromColor,  maxBrightness - i);
    analogWrite(toColor, i);
    delay(delayMS);
  }
}

void fadeOut(byte color, byte delayMS = FADESPEED, byte minBrightness = 0, byte maxBrightness = 255) {
  for (int out = maxBrightness; out > minBrightness; out--) {
    analogWrite(color, out);
    delay(delayMS);
  }
}

void fadeIn(byte color, byte delayMS = FADESPEED, byte minBrightness = 0, byte maxBrightness = 255) {
  for (int in = minBrightness; in <= maxBrightness; in++) {
    analogWrite(color, in);
    delay(delayMS);
  }
}

