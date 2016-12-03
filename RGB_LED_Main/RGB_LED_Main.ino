// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define REDPIN 9
#define GREENPIN 10
#define BLUEPIN 11
#define MAX_BRIGHTNESS 100

#define FADESPEED 100     // make this higher to slow down

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
}


void loop() {
  int r, g, b;
  int w = 150;
  int q = 0;
  int poo = 1;
  //fade from red to green
  //for (r = 0; r <= MAX_BRIGHTNESS; r++) {
  //analogWrite(REDPIN, r);
  //delay(FADESPEED);

  // fade from blue to violet
      for (r = 0; r <= MAX_BRIGHTNESS; r++) {
        analogWrite(REDPIN, r);
        delay(FADESPEED);
      }
  // fade from violet to red
  for (b = MAX_BRIGHTNESS; b > 0; b--) {
  analogWrite(BLUEPIN, b);
  delay(FADESPEED);
  }
  // fade from red to yellow
  for (g = 0; g <= MAX_BRIGHTNESS; g++) {
  analogWrite(GREENPIN, g);
  delay(FADESPEED);
  }
  // fade from yellow to green
  for (r = MAX_BRIGHTNESS; r > 0; r--) {
  analogWrite(REDPIN, r);
  delay(FADESPEED);
  }
  // fade from green to teal
  for (b = 0; b <= MAX_BRIGHTNESS; b++) {
  analogWrite(BLUEPIN, b);
  delay(FADESPEED);
  }
  // fade from teal to blue
  for (g = MAX_BRIGHTNESS; g > 0; g--) {
  analogWrite(GREENPIN, g);
  delay(FADESPEED);
      colorFade(REDPIN, GREENPIN);
      colorFade(GREENPIN, REDPIN);
      fadeOut(REDPIN);
      fadeIn(GREENPIN);
      fadeOut(GREENPIN);
      fadeIn(REDPIN);
  
}
}
void colorFade(byte fromColor, byte toColor) {
  int i = 0;
  for (i = 0; i <= MAX_BRIGHTNESS; i++) {
    analogWrite(fromColor,  MAX_BRIGHTNESS - i);
    delay(FADESPEED);
    analogWrite(toColor, i);
    delay(FADESPEED);
  }
}

void fadeOut(byte color) {
  for (int out = MAX_BRIGHTNESS; out > 0; out--) {
    analogWrite(color, out);
    delay(FADESPEED);
  }
}

void fadeIn(byte color) {
  for (int in = 0; in <= MAX_BRIGHTNESS; in++) {
    analogWrite(color, in);
    delay(FADESPEED);
  }
}

