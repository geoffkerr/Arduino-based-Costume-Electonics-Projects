#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN_HANDS    1
#define LED_PIN_POWER    0

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 7

#define DELAY_TIME 50

// Declare our NeoPixel strip object:
Adafruit_NeoPixel hands(LED_COUNT, LED_PIN_HANDS, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel power(LED_COUNT, LED_PIN_POWER, NEO_GRB + NEO_KHZ800);

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.
  // put your setup code here, to run once:

  // setup LEDs
  hands.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  power.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  hands.setBrightness(127); // Set BRIGHTNESS to about 0 (max = 255)
  power.setBrightness(127); // Set BRIGHTNESS to about 0 (max = 255)
  hands.Color(0,0,0);       //takes RGB values, from 0,0,0 up to 255,255,255
  power.Color(0,0,0);       //takes RGB values, from 0,0,0 up to 255,255,255
  hands.show();             // Turn on all pixels ASAP
  power.show();             // Turn on all pixels ASAP
}

unsigned int bright = 0;
bool         fade   = true;

void manageHandsTransitions()
{
  //fade in
  if(fade == true)
  {
    bright += 5;
    if (bright == 255)
    {
      fade = false;
    }
  }
  //fade out
  else
  {
    bright -= 5;
    if (bright == 0)
    {
      fade = true;
    }
  }
  hands.setPixelColor(0,0,0,bright);    //takes RGB values, from 0,0,0 up to 255,255,255
  hands.setPixelColor(1,0,0,bright);    //takes RGB values, from 0,0,0 up to 255,255,255
  hands.setPixelColor(2,0,0,bright);    //takes RGB values, from 0,0,0 up to 255,255,255
  hands.setPixelColor(3,0,0,bright);    //takes RGB values, from 0,0,0 up to 255,255,255
  hands.setPixelColor(4,0,0,bright);    //takes RGB values, from 0,0,0 up to 255,255,255
  hands.setPixelColor(5,0,0,bright);    //takes RGB values, from 0,0,0 up to 255,255,255
  hands.setPixelColor(6,0,0,bright);    //takes RGB values, from 0,0,0 up to 255,255,255
  hands.show();
}

unsigned int powerStep = 0;

void managePowerTransitions()
{
  switch(powerStep)
  {
    case 0 :
      power.setPixelColor(0,0,0,0);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(1,0,0,255);  //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(2,0,0,0);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(3,0,0,0);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(4,0,0,63);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(5,0,0,127);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(6,0,0,191);  //takes RGB values, from 0,0,0 up to 255,255,255
      powerStep++;
      break;
    case 1 :
      power.setPixelColor(0,0,0,0);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(1,0,0,191);  //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(2,0,0,255);  //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(3,0,0,0);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(4,0,0,0);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(5,0,0,63);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(6,0,0,127);    //takes RGB values, from 0,0,0 up to 255,255,255
      powerStep++;
      break;
    case 2 :
      power.setPixelColor(0,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(1,0,0,127);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(2,0,0,191);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(3,0,0,255);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(4,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(5,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(6,0,0,63);      //takes RGB values, from 0,0,0 up to 255,255,255
      powerStep++;
      break;
    case 3 :
      power.setPixelColor(0,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(1,0,0,63);     //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(2,0,0,127);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(3,0,0,191);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(4,0,0,255);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(5,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(6,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      powerStep++;
      break;
    case 4 :
      power.setPixelColor(0,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(1,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(2,0,0,63);     //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(3,0,0,127);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(4,0,0,191);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(5,0,0,255);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(6,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      powerStep++;
      break;
    default:
    case 5 :
      power.setPixelColor(0,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(1,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(2,0,0,0);      //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(3,0,0,63);     //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(4,0,0,127);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(5,0,0,191);    //takes RGB values, from 0,0,0 up to 255,255,255
      power.setPixelColor(6,0,0,255);    //takes RGB values, from 0,0,0 up to 255,255,255
      powerStep = 0;
      break;
  }
  power.show();
}


void loop() {
  manageHandsTransitions();
  managePowerTransitions();
  delay(DELAY_TIME);
}
