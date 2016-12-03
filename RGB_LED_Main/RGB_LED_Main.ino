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
//  int r, g, b;
//  int w = 150;
//  int q = 0;
//  int poo = 1;
//  //fade from red to green
//  //for (r = 0; r <= MAX_BRIGHTNESS; r++) {
//  //analogWrite(REDPIN, r);
//  //delay(FADESPEED);
//
//  // fade from blue to violet
//      for (r = 0; r <= MAX_BRIGHTNESS; r++) {
//        analogWrite(REDPIN, r);
//        delay(FADESPEED);
//      }
//  // fade from violet to red
//  for (b = MAX_BRIGHTNESS; b > 0; b--) {
//  analogWrite(BLUEPIN, b);
//  delay(FADESPEED);
//  }
//  // fade from red to yellow
//  for (g = 0; g <= MAX_BRIGHTNESS; g++) {
//  analogWrite(GREENPIN, g);
//  delay(FADESPEED);
//  }
//  // fade from yellow to green
//  for (r = MAX_BRIGHTNESS; r > 0; r--) {
//  analogWrite(REDPIN, r);
//  delay(FADESPEED);
//  }
//  // fade from green to teal
//  for (b = 0; b <= MAX_BRIGHTNESS; b++) {
//  analogWrite(BLUEPIN, b);
//  delay(FADESPEED);
//  }
//  // fade from teal to blue
//  for (g = MAX_BRIGHTNESS; g > 0; g--) {
//  analogWrite(GREENPIN, g);
//  delay(FADESPEED);
//      colorFade(REDPIN, GREENPIN);
//      colorFade(GREENPIN, REDPIN);
      fadeOut(REDPIN, 100, 0, 25);
      fadeIn(GREENPIN, 5, 0, 25);
      fadeOut(GREENPIN, 5, 0, 25);
      fadeIn(REDPIN, 100, 0, 25);
  
//}
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

