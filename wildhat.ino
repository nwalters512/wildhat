#include <FastLED.h>

#define NUM_LEDS 44
#define DATA_PIN    10
#define CLOCK_PIN   11
#define BRIGHTNESS 32

// Set up LED strip
CRGB leds[NUM_LEDS];

void setup() {
  // I used APA102-based LEDs; change this as needed to match your setup
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN>(leds, NUM_LEDS);
  // Brightness is limited to conserve power
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  bounceSegment(5, 5, CRGB::Red);
  bounceSegment(5, 5, CRGB::Blue);
  rainbowCycle(5, 10);
}

// Bounces a segment of LEDs from one end of the strip to another
void bounceSegment(int segmentLength, uint8_t numBounces, CRGB color) {

  int segStart = 0;
  // True is moving low to high, false is moving high to low
  int segDirection = true;

  int numBouncesCounted = 0;

  while(numBouncesCounted < numBounces) {

    // Initialize all LEDs to off
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = 0;
    }

    // Turn on LEDs that should be lit this cycle
    for(int i = segStart; i < segStart + segmentLength; i++) {
      leds[i] = color;
    }

    // If we reached either end of the strip, reverse direction
    if(segStart + segmentLength >= NUM_LEDS && segDirection == true) {
      segDirection = false;
    } 
    else if (segStart == 0 && segDirection == false) {
      segDirection = true;
      // We're back at the start of the strip; increment bounce count
      numBouncesCounted++;
    }

    // Move the start of the segment in the appropriate direction
    if(segDirection) {
      segStart++;
    } 
    else {
      segStart--;
    }

    // Flush to the strip and delay to give a nice animation (roughly 40 FPS)
    FastLED.show();
    delay(25);
  }
}

// Animates a nainbow in a circle around the hat
void rainbowCycle(int cycles, uint8_t wait) {  
  for(int j = 0; j < 256*cycles; j++) {
    for(int i = 0; i < NUM_LEDS; i++) {
      // Map to a hue in the range 0-255
      // This will get us a color on the rainbow
      leds[i] = CHSV((i * 256 / NUM_LEDS) + j & 255, 255, 255);
    }

    // Flush to the strip and delay to give a nice animation (roughly 40 FPS)
    FastLED.show();
    delay(wait);
  }
}
