# WildHat
An LED-enhanced hard hat designed to provide maximum swag at FRC competitions.

![WildHat](http://i.imgur.com/FtOrVpPm.jpg)

### Setup
This project requires the [FastLED](https://github.com/FastLED/FastLED) library; make sure it is properly installed in your Arduino libraries folder before beginning.

By default, the data line is on digital out 10 and clock is on digital out 11. However, this can be changed by adjusting the apppropriate ```#define```s.

### Hardware

![WildHat internals](http://i.imgur.com/IxVQcdVl.jpg)

The base of the WildHat is a standard [Grainger hard hat](http://www.grainger.com/product/MSA-Front-Brim-Hard-Hat-WP44076/). A slot was cut in the back to allow the LED wires to pass from the interior of the hat to the exterior.

The microcontroller I used is the [Arduino Pro Mini](http://www.arduino.cc/en/Main/ArduinoBoardProMini), although any small Arduino-based device with SPI support should work.

I opted to use APA102-based LEDs (Adafruit markets them as [DotStar LEDs](http://www.adafruit.com/categories/340)); they're readily available for low prices from Chinese suppliers (I bought mine on eBay). The LEDs were attached to the hat using double-sided foam tape. I was originally going to use hot glue, but the LED sheathing is silicone-based, so it didn't stick.

The hat is powered with a [3.7V lithium-polymer rechargable battery](https://www.adafruit.com/products/258). The one I used was rated for 1200mAh; I would've liked to get a higher capacity to get more awesomeness out of the hat, but they were out of stock when I was ordering parts. I also integrated a [lithium-polymer battery charger](https://www.adafruit.com/products/1904) directly into the design. It has the appropriate circuitry for charging li-po batteries and it provides convenient breakouts for the battery leads. I soldered jumper wires directly to the BAT and GND holes on the charger; as you can see in the picture, this provided an easy way to anchor the charging board to the breadboard.

A 1000 µF capacitor is placed across the power leads of the LED strip to prevent damage from the initial onrush of current. Mine is 16V, but according to [Adafruit](https://learn.adafruit.com/adafruit-neopixel-uberguide/power), anything about 6.3V will work just fine.

I integrated an [FTDI adapter](https://www.sparkfun.com/products/9716) into the helmet (by integrated I mean I taped one to the back and ran some wires to the Arduino). I knew I'd be modifying the softwarea lot, so I decided to affix it semi-permanently to the hat.

### Future enhancement goals
* The breadboard/Arduino/charger/FTDI assembly is large, bulky, and has a lot of potential points of failure. I'd love to design a circuit board with all the required components integrated into it.
* In my opinion, the hat would look a lot cooler in black; however, painting it with black spray paint that was designed for plastics proved to be an abysmal failure; there was absolutely no adhesion to the hat. The best option is probably to simply order a black plastic hard hat!
* The team logo and numbers are currently just printed on printer paper and taped to the hat with packing tape; it's functional, but not very pretty. If I can find a way, I'd like to manufacture some vinyl stickers that would cleanly adhere and hopefully conform to the curved surface of the hat better.
* My team's LED sign boards that we use have competition have an integrated 2-line display and buttons to allow the selection of LED programs on the fly. Integrating that into the back of the hat would be very cool.
