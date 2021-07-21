#include <Adafruit_NeoPixel.h> 
  
//Designamos nuestro pin de datos 
#define PIN 6 
//Designamos cuantos pixeles tenemos en nuestra cinta led RGB 
#define NUMPIXELS 9
 
//Definimos el número de pixeles de la cinta y el pin de datos 
//   Parámetro 1 = número de pixeles de la cinta 
//   Parámetro 2 = número de pin de datos del Arduino 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); 
 
// IMPORTANTE: Para reducir el riesgo de dañar los pixeles de la cinta, añada un condensador de 1000 uF a través de 
// los cables de alimentación de la cinta, agregue una resistencia de 300-500 Ohm en la entrada de datos del primer pixel 
// Y reduzca la distancia entre Arduino y el primera pixel.  
// Evite realizar conexiones en el circuito vivo si lo va a hacer, conecte GND primero. 
 
void setup() { 
// Inicializamos nuestra cinta led RGB 
  pixels.begin();  
   
} 
 
void loop() { 
 
  //Definimos nuestras variables de tipo uint32 para cada color que utilizaremos 
  // pixels.Color toma valores en RGB, desde 0,0,0 hasta 255,255,255 
   uint32_t cafe = pixels.Color(110,39,10);
   uint32_t amarillo = pixels.Color(250,250,0);
   uint32_t naranja = pixels.Color(255,70,0); 
   uint32_t blanco = pixels.Color(255,255,255); 
   uint32_t negro = pixels.Color(0,0,0); 
 
  int delayval = 150; // Pausa de cincuenta milisegundos 
 pixels.setBrightness(20);
  // La numeración de leds en la cinta RGB es la siguiente:  el primer pixel es 0, el segundo es 1 y asi sucesivamente hasta el número total de leds menos uno 
  for(int i=NUMPIXELS; i<=0;i++){ 
 
    pixels.setPixelColor(i, cafe); // Brillo moderado en cafe
 
    pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB 
 
    delay(delayval); // Pausa por un periodo de tiempo (en milisegundos). 
 
  } 
   
    for(int i=0;i<NUMPIXELS;i++){ 
 
    pixels.setPixelColor(i, amarillo); // Brillo moderado en amarillo 
 
    pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB 
 
    delay(delayval); // Pausa por un periodo de tiempo (en milisegundos). 
 
  } 
     
    for(int i=0;i<NUMPIXELS;i++){ 
 
    pixels.setPixelColor(i, naranja); // Brillo moderado en naranja
     
    pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB 
 
    delay(delayval); // Pausa por un periodo de tiempo (en milisegundos). 
 
  } 
  for(int i=0;i<NUMPIXELS;i++){ 
 
    pixels.setPixelColor(i, blanco); // Brillo moderado en blanco 
 
    pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB 
 
    delay(delayval); // Pausa por un periodo de tiempo (en milisegundos). 
 
  } 
  for(int i=0;i<NUMPIXELS;i++){ 
 
    pixels.setPixelColor(i, negro); // Brillo moderado en negro
 
    pixels.show();   // Mostramos y actualizamos el color del pixel de nuestra cinta led RGB 
  }
    for(int i=0;i<NUMPIXELS;i++){         
    delay(100); // Pausa por un periodo de tiempo (en milisegundos). 
    }
} 
