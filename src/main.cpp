#include "Arduino.h"

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
#define BUTTON_PIN 2
#define BRIGHTNESS_PIN A0
#define NUM_MODES 2
#define SLOW_MODE 1
#define FAST_MODE 2
volatile byte mode = SLOW_MODE;
volatile boolean modeChange = false;

// Function declarations
void colorFade(byte fromColor, byte toColor, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);
void fadeOut(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);
void fadeIn(byte color, long durationMS = 1000, byte minBrightness = 0, byte maxBrightness = 255);
void handleModeEvent();
void fastMode(byte maxBrightness);
void slowMode(byte maxBrightness);


void setup() {
    Serial.begin(115200);
    // Initialize the color pins as outputs and turn them off
    pinMode(RED_PIN, OUTPUT);
    analogWrite(RED_PIN, 0);
    pinMode(GREEN_PIN, OUTPUT);
    analogWrite(GREEN_PIN, 0);
    pinMode(BLUE_PIN, OUTPUT);
    analogWrite(BLUE_PIN, 0);

    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BRIGHTNESS_PIN, INPUT);
    attachInterrupt((uint8_t) digitalPinToInterrupt(BUTTON_PIN), handleModeEvent, FALLING);
}


void loop() {
    byte maxBrightness = (byte) ((analogRead(BRIGHTNESS_PIN) / 1024) * 255);
    if (maxBrightness <= 50) {
        maxBrightness = 50;
    }
    Serial.println(maxBrightness);

    // Determine mode and call the appropriate function
    switch (mode) {
        case SLOW_MODE:
            slowMode(maxBrightness);
            break;
        case FAST_MODE:
            fastMode(maxBrightness);
            break;
        default:break;
    }

}

void handleModeEvent() {
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    modeChange = true;

    // Don't do anything while the button is held down
    while (digitalRead(BUTTON_PIN) == LOW) {}

    // Increment the mode state and signal the change
    mode++;

    // Fix the state (reset back to mode 1 if necessary)
    if (mode > NUM_MODES) {
        mode = 1;
    }

    modeChange = false;
}

void fastMode(byte maxBrightness) {
    // Fade red in and out with a random "on" duration
    byte brightness = (byte) random(5, maxBrightness);
    fadeIn(RED_PIN, 100, 0, brightness);
    delay((unsigned long) random(200, 1000));
    fadeOut(RED_PIN, 100, 0, brightness);

    // Fade green in and out with a random "on" duration
    brightness = (byte) random(5, maxBrightness);
    fadeIn(GREEN_PIN, 100, 0, brightness);
    delay((unsigned long) random(200, 1000));
    fadeOut(GREEN_PIN, 100, 0, brightness);
}

void slowMode(byte maxBrightness) {
    // Fade red in and out with a random "on" duration
    byte brightness = (byte) random(50, maxBrightness);
    fadeIn(RED_PIN, 500, 0, brightness);
    delay((unsigned long) random(500, 5000));
    fadeOut(RED_PIN, 500, 0, brightness);

    // Fade green in and out with a random "on" duration
    brightness = (byte) random(5, maxBrightness);
    fadeIn(GREEN_PIN, 500, 0, brightness);
    delay((unsigned long) random(500, 5000));
    fadeOut(GREEN_PIN, 500, 0, brightness);
}

/*
 * colorFade
 * Fade from one primary color to another. You may optionally set the duration
 * which is defaulted to one second and you can optionally set the min and max
 * brightness values.
 * @param fromColor the pin for the color you are changing from
 * @param toColor the pin for the color you are changing to
 * @param durationMS  the amount of time (in milliseconds) you want the fade to take
 * @param minBrightness the lowest brightness value for the colors
 * @param maxBrightness the highest brightness value for the colors
 */
void colorFade(byte fromColor, byte toColor, long durationMS, byte minBrightness, byte maxBrightness) {
    // Calculate the delay time increment required to satisfy the total duration desired
    long delayIncrement = durationMS / (maxBrightness - minBrightness);
    long currentTime = 0;
    for (int i = minBrightness; i <= maxBrightness; i++) {
        currentTime = millis();
        analogWrite(fromColor,  maxBrightness - i);
        analogWrite(toColor, i);
        while(millis() - currentTime <= delayIncrement && !modeChange) {}
        if (modeChange) {
            break;
        }
    }
}

/*
 * fadeOut
 * Fade a color out completely. You may optionally set the duration which is defaulted
 * to one second and you can optionally set the min and max brightness values.
 * @param color the pin for the color you are fading out
 * @param durationMS  the amount of time (in milliseconds) you want the fade to take
 * @param minBrightness the lowest brightness value for the colors
 * @param maxBrightness the highest brightness value for the colors
 */
void fadeOut(byte color, long durationMS, byte minBrightness, byte maxBrightness) {
    // Calculate the delay time increment required to satisfy the total duration desired
    long delayIncrement = durationMS / (maxBrightness - minBrightness);
    long currentTime = 0;
    for (int out = maxBrightness; out > minBrightness; out--) {
        currentTime = millis();
        analogWrite(color, out);
        while(millis() - currentTime <= delayIncrement && !modeChange) {}
        if (modeChange) {
            break;
        }
    }
}

/*
 * fadeIn
 * Fade a color in completely. You may optionally set the duration which is defaulted
 * to one second and you can optionally set the min and max brightness values.
 * @param color the pin for the color you are fading in
 * @param durationMS  the amount of time (in milliseconds) you want the fade to take
 * @param minBrightness the lowest brightness value for the colors
 * @param maxBrightness the highest brightness value for the colors
 */
void fadeIn(byte color, long durationMS, byte minBrightness, byte maxBrightness) {
    // Calculate the delay time increment required to satisfy the total duration desired
    long delayIncrement = durationMS / (maxBrightness - minBrightness);
    long currentTime = 0;
    for (int in = minBrightness; in <= maxBrightness; in++) {
        currentTime = millis();
        analogWrite(color, in);
        while(millis() - currentTime <= delayIncrement && !modeChange) {}
        if (modeChange) {
            break;
        }
    }
}

