#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel tira = Adafruit_NeoPixel(9, 6, NEO_GRB + NEO_KHZ800);

// Variables para mantener valores de brillo que van desde
//0 (apagado) a 255 (totalmente encendido
int Rojo_value=0;
int verde_value=0;
int azul_value=0;
int intensidad_value=0;
char BluetoothData;

void setup() {
 tira.begin();
 tira.show(); //deja los pixeles apagados
 Serial.begin(9600);//inicia la comunicacion serial
}
void loop(){
// Procese cualquier información que provenga del enlace serie bluetooth
  if (Serial.available()){
    BluetoothData=Serial.read(); //Get next character from bluetooth
    if(BluetoothData=='R') Rojo_value=Serial.parseInt(); // Leer valor rojo
    if(BluetoothData=='V') verde_value=Serial.parseInt(); // Leer valor verde
    if(BluetoothData=='B') azul_value=Serial.parseInt(); // Leer valor azul
    if(BluetoothData=='I') intensidad_value=Serial.parseInt(); // Leer la intensidad de las 
    //neopixeles
  }
 
tira.setBrightness(intensidad_value);
for(int i=0; i<9; i++){
tira.setPixelColor(i, Rojo_value, verde_value, azul_value); //posicion, R, G, B
tira.show(); 
}
}
