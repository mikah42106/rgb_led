// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define REDPIN 9
#define GREENPIN 10
#define BLUEPIN 11
#define MAX_BRIGHTNESS 100

#define FADESPEED 100     // make this higher to slow down

// Function declarations
void colorFade(byte fromColor, byte toColor, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);
void fadeOut(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);
void fadeIn(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);


void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}


void loop() {
//  colorFade(REDPIN, GREENPIN, 4000, 0, 25);
//  colorFade(GREENPIN, REDPIN, 2000, 0, 25);
  fadeOut(REDPIN, 2000, 0, 25);
  fadeIn(GREENPIN, 500, 0, 25);
  fadeOut(GREENPIN, 500, 0, 25);
  fadeIn(REDPIN, 2000, 0, 25);
}

void colorFade(byte fromColor, byte toColor, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255) {
  // Calculate the delay time increment required to satisfy the total duration desired
  long delayIncrement = durationMS / (maxBrightness - minBrightness);
  for (int i = minBrightness; i <= maxBrightness; i++) {
    analogWrite(fromColor,  maxBrightness - i);
    analogWrite(toColor, i);
    delay(delayIncrement);
  }
}

void fadeOut(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255) {
  // Calculate the delay time increment required to satisfy the total duration desired
  long delayIncrement = durationMS / (maxBrightness - minBrightness);
  for (int out = maxBrightness; out > minBrightness; out--) {
    analogWrite(color, out);
    delay(delayIncrement);
  }
}

void fadeIn(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255) {
  // Calculate the delay time increment required to satisfy the total duration desired
  long delayIncrement = durationMS / (maxBrightness - minBrightness);
  for (int in = minBrightness; in <= maxBrightness; in++) {
    analogWrite(color, in);
    delay(delayIncrement);
  }
}

