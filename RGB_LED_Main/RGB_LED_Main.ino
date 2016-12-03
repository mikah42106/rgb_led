#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
#define MAX_BRIGHTNESS 100

// Function declarations
void colorFade(byte fromColor, byte toColor, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);
void fadeOut(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);
void fadeIn(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);


void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


void loop() {
//  colorFade(RED_PIN, GREEN_PIN, 4000, 0, 25);
//  colorFade(GREEN_PIN, RED_PIN, 2000, 0, 25);
  fadeOut(RED_PIN, 2000, 0, 25);
  fadeIn(GREEN_PIN, 500, 0, 25);
  fadeOut(GREEN_PIN, 500, 0, 25);
  fadeIn(RED_PIN, 2000, 0, 25);
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

