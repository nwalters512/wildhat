#include <FastLED.h>

#define NUM_LEDS 44
#define DATA_PIN    10
#define CLOCK_PIN   11
#define BRIGHTNESS 32

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  Serial.begin(9600);
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0xFF0000;      // 'On' color (starts red)

void loop() {
  bounceSegment(5, 5, CRGB::Red);
  bounceSegment(5, 5, CRGB::Blue);
  rainbowCycle(5, 10);
}

// Bounces a segment of LEDs from one end of the strip to another
void bounceSegment(int segmentLength, uint8_t numBounces, CRGB color) {
  // True is moving low to high, false is moving high to low

  int segStart = 0;
  int segDirection = true;

  int numBouncesCounted = 0;

  while(numBouncesCounted < numBounces) {

    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = 0;
    }

    for(int i = segStart; i < segStart + segmentLength; i++) {
      leds[i] = color;
    }

    if(segStart + segmentLength >= NUM_LEDS && segDirection == true) {
      segDirection = false;
    } 
    else if (segStart == 0 && segDirection == false) {
      segDirection = true;
      // one bounce completed
      numBouncesCounted++;
    }

    if(segDirection) {
      segStart++;
    } 
    else {
      segStart--;
    }

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
    FastLED.show();
    delay(wait);
  }
}





