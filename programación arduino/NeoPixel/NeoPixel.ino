#include <Adafruit_NeoPixel.h>
#define neopixels_pin 6
#define neopixels_num 5

Adafruit_NeoPixel neopixels_strip(neopixels_num, neopixels_pin,NEO_GRB* NEO_KHZ800);
enum Color_pallete{
  Red,
  Green,
  Blue,
};
void setup() {
Serial.begin(9600);
neopixels_strip.begin();
}

void loop() {

    for(int i=0; i<5; i++)
    {
    neopixels_strip.setPixelColor(i,255,0,0);
    neopixels_strip.show();
    }
 
 
  
}
