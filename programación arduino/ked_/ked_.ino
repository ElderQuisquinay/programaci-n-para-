#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    9
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}
void loop() {
   int a;
   int brillo;
   a=analogRead(A0);
   brillo=analogRead(A1)/6;
   FastLED.setBrightness(brillo);
   a=analogRead(A0);  
  for (int i = 0; i <= 9; i++) {
   brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
   a=analogRead(A0);
   brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 0, 0);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 0, 255);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 255, 0);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 100, 255, 255);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 200, 100);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 100, 20, 255);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 100, 100);
    FastLED.show();
    delay(a);
  }

 // *************************************
    for (int i = 0; i <= 9; i++) {
      a=analogRead(A0);
      brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 100, 0, 255);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 100, 0);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 100, 255);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 255, 100);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 100, 255, 25);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 55, 200, 100);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 100, 20, 25);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 25, 100, 200);
    FastLED.show();
    delay(a);
  }
 // *************************************
    for (int i = 0; i <= 9; i++) {
      a=analogRead(A0);
      brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 100, 69, 255);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 255, 100, 68);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 58, 100, 55);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 65, 55, 100);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 60, 255, 200);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 55, 20, 100);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 0; i <= 9; i++) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 10, 20, 25);
    FastLED.show();
    delay(a);
  }
  
  for (int i = 9; i >= 0; i--) {
    a=analogRead(A0);
    brillo=analogRead(A1);
   FastLED.setBrightness(brillo);
    leds[i] = CRGB ( 25, 100, 20);
    FastLED.show();
    delay(a);
 
}
}
