#include <Adafruit_NeoPixel.h> //Includes specific library for driving WS2811 adressable leds 
//#define BUTTON_PIN   2  Commented out because no button for this test, but       
 /*Digital IO pin connected to the button.  This will be driven with a pull-up resistor 
  *so the switch should pull the pin to ground momentarily.  On a high -> low transition 
  *the button press logic will execute.*/
#define PIXEL_PIN    4    // Digital IO pin connected to the LED strip
#define PIXEL_COUNT 10    // Number of LEDs in strip

// Parameter 1 = pin number (most are valid) 
// Parameter 2 = number of pixels in strip, Each LED in stip will draw 0.06 Amps so plan accordingly 
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup (){
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

float x = 0.;

void loop (){
  int i = 0;
  
  
  strip.show();
  for(; i < 10; i++) { 
    for(int j = 0; j < 10; j++) {
      if (j != i) {
        strip.setPixelColor(j, purpSend(x));
      } else {
        strip.setPixelColor(i, 0, 254, 0);
      }
      strip.show();
    }
    x += .0001;
    //delay(10);
  }
  
  for(; i > 0; i--) {
    for(int j = 0; j < 10; j++) {
      if (j != i) {
          strip.setPixelColor(j, purpSend(x));
      } else {
        strip.setPixelColor(i, 0, 254, 0);
      }
      strip.show();
    }
    x += .0001;
    //delay(10);
  }
}

uint32_t purpSend(float x) {
  uint8_t fad =(uint8_t)( 125 * (125* sin(x))).;
  
  uint32_t ret = strip.Color(fad, 0, 255 - fad);
  return ret;
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}











































































































