#include <LiquidCrystal_I2C.h>

// aqui se configuran los pines para la pantalla
LiquidCrystal_I2C lcd(0x27 ,16,2);

int EchoPin=7; 
int TriggerPin=8;
long duration, distanceCm; 
int cm;
void setup() {
lcd.init();
lcd.backlight();
lcd.home();
pinMode(TriggerPin, OUTPUT);
pinMode(EchoPin, INPUT);
pinMode(5, OUTPUT);

}
 
void loop() {
  cm = ping(TriggerPin, EchoPin);
   
  if(cm<=50){
  lcd.clear();
  lcd.setCursor ( 0, 0);
  lcd.print("Dispensando Jabon");
  digitalWrite(5, HIGH);
  }
  else{
    lcd.clear();
  lcd.setCursor ( 0, 0);
  lcd.print("Distancia:   ");// Iimprimir "distancia"
  lcd.setCursor ( 0, 1 );
  lcd.print(cm);// Iimprimir la variable cm
  delay(1000);// espera un sregundo
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   digitalWrite(5, LOW);
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



   if(cm<=50){
  c=0;
  lcd.clear();
  lcd.setCursor ( 0, 0);
  lcd.print("Dispensando Jabon");
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
  a=a+1;
  }
  else{
    lcd.clear();
  lcd.setCursor ( 0, 0);
  lcd.print("Distancia:   ");// Iimprimir "distancia"
  lcd.setCursor ( 0, 1 );
  lcd.print(cm);// Iimprimir la variable cm
  delay(1000);// espera un sregundo
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   digitalWrite(6, LOW);
   digitalWrite(4, LOW);
digitalWrite(3, HIGH);
  }
  
