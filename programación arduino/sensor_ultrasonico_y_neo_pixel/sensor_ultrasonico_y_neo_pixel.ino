#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel tira = Adafruit_NeoPixel(6, 6, NEO_GRB + NEO_KHZ800);
int EchoPin =8; 
int TriggerPin = 9;
long duration, distanceCm; 
void setup() {
  Serial.begin(9600);
  tira.begin();
  tira.show(); //deja los pixeles apagados
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}
 
void loop() {
  int cm = ping(TriggerPin, EchoPin);
  Serial.print("Distancia:   ");// Iimprimir "distancia"
  Serial.println(cm);// Iimprimir la variable cm
  delay(50);// espera un sregundo
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  if(cm<=4){
 for(int i=0; i<6; i++){
 tira.setPixelColor(i, 255, 0, 0); //posicion, R, G, B
 tira.show(); 
 delay(500);
 }
  }
 else if(cm<20){
  for(int i=6; i>=0; i--){
 tira.setPixelColor(i, 0, 0, 255); //posicion, R, G, B
 tira.show(); 
 delay(500);
}
  }
else if(cm>=20){
for(int i=0; i<6; i++){
tira.setPixelColor(i, 0, 255, 0); //posicion, R, G, B
tira.show(); 
delay(500);
}
  }
  }
 
int ping(int TriggerPin, int EchoPin) {
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
  distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;

  }
  
