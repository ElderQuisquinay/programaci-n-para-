#include <Adafruit_NeoPixel.h> //incluimos la libreria de neopixeles 
#define pin 11 //establecemos la variable pin con el pin 11 del arduino 
#define numpixels 7 //los neopixeles que encenderemos 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numpixels, pin, NEO_GRB + NEO_KHZ800); 
//establecemos todo las reglas a pixels 
const int Pirpin=12; //nombramos pinpir con el pin 12
int   PirState=LOW;//nombramos un estado en bajo para pirstate
int val=0; 

void setup() {
pixels.begin();//iniciamos los neopixeles 
pinMode(Pirpin, INPUT);//establecemos pirpin como entrada 
Serial.begin(9600);
}
void loop() {
int value=digitalRead(Pirpin);//vemos que estado tenemos si HIGH O LOW
 pixels.setBrightness(20);//establecemos la intencidad de los neopixeles 
if(value==HIGH){//sentencia if 
for(int i=0; i<7; i++){//vucle for 
pixels.setPixelColor(i, 255,39,10);//RGB
pixels.show();
} 
delay(1000);//retraso de tiempo de 1 segundo 
}
else{//else
for(int i=0; i<7;i++){//vucle for  
pixels.setPixelColor(i, 0,0,0);//apagamos los RGB
pixels.show();
}
}
}
