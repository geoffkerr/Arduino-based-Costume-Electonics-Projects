#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    1

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 1

#define DELAY_TIME 100

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.
  // put your setup code here, to run once:

  // setup LEDs
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.setBrightness(200); // Set BRIGHTNESS to about 0 (max = 255)
  strip.show();             // Turn on all pixels ASAP
  strip.Color(255,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.show();             // Turn on all pixels ASAP

}

unsigned int bright = 0;

void loop() {
  //fade in
  while(bright < 250)
  {
    bright += 10;
    strip.setPixelColor(0,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(1,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
    strip.show();
    delay(DELAY_TIME);
  }

  //shimmer
  bright = 255;
  strip.setPixelColor(0,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.setPixelColor(1,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.show();
  delay(DELAY_TIME);
  bright = 150;
  strip.setPixelColor(0,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.setPixelColor(1,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.show();
  delay(DELAY_TIME);
  bright = 255;
  strip.setPixelColor(0,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.setPixelColor(1,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.show();
  delay(DELAY_TIME);
  bright = 150;
  strip.setPixelColor(0,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.setPixelColor(1,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.show();
  delay(DELAY_TIME);
  bright = 255;
  strip.setPixelColor(0,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.setPixelColor(1,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
  strip.show();
  delay(DELAY_TIME);

  //fade out
  while(bright > 10)
  {
    bright -= 10;
    strip.setPixelColor(0,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(1,bright,0,10);    //takes RGB values, from 0,0,0 up to 255,255,255
    strip.show();
    delay(DELAY_TIME);
  }
  bright = 0;
}
