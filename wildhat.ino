#include <FastLED.h>

#define NUM_LEDS 44

#define DATA_PIN    10
#define CLOCK_PIN   11

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN>(leds, NUM_LEDS);

  //strip.begin(); // Initialize pins for output
  //strip.show();  // Turn all LEDs off ASAP
  //strip.setBrightness(50);

  Serial.begin(9600);
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0xFF0000;      // 'On' color (starts red)

void loop() {
  //rainbowCycle(0);
  bounceSegment(3, 4, CRGB::Red);
  delay(2000);
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

    delay(20);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {

  uint16_t i, j;

  for(j = 0; j < 256*5; j++) { // 5 cycles of all colors on wheel
    for(i = 0; i < NUM_LEDS; i++) {
      uint32_t color = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      leds[i].r = (uint8_t)(color >> 16);
      leds[i].g = (uint8_t)(color >>  8);
      leds[i].b = (uint8_t)color;
    }
    FastLED.show();
    delay(wait);
  }

}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  CRGB color;
  if(WheelPos < 85) {
    color.r = WheelPos * 3;
    color.g = 255 - WheelPos * 3;
    color.b = 0;
    return color;
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    color.r = 255 - WheelPos * 3;
    color.g = 0;
    color.b = WheelPos * 3;
    return color;
  } 
  else {
    WheelPos -= 170;
    color.r = 0;
    color.g = WheelPos * 3;
    color.b = 255 - WheelPos * 3;
    return color;
  }
}





