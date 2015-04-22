# WildHat
An LED-enhanced hard hat designed to provide maximum swag at FRC competitions.

![WildHat](http://i.imgur.com/FtOrVpPm.jpg)

### Setup
This project requires the [FastLED](https://github.com/FastLED/FastLED) library; make sure it is properly installed in your Arduino libraries folder before beginning.

By default, the data line is on digital out 10 and clock is on digital out 11. However, this can be changed by adjusting the apppropriate ```#define```s.

### Hardware
The base of the WildHat is a standard [Grainger hard hat](http://www.grainger.com/product/MSA-Front-Brim-Hard-Hat-WP44076/). A slot was cut in the back to allow the LED wires to pass from the interior of the hat to the exterior.

The microcontroller I used is the [Arduino Pro Mini](http://www.arduino.cc/en/Main/ArduinoBoardProMini), although any small Arduino-based device with SPI support should work.

I opted to use APA102-based LEDs (Adafruit markets them as [DotStar LEDs](http://www.adafruit.com/categories/340)); they're readily available for low prices from Chinese suppliers (I bought mine on eBay).
