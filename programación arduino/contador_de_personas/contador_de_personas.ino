#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27 ,16,2);
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
const int Pirpin=12;
int   PirState=LOW;
int val=0;
int contar=0;
int pinzumbador = 10; // pin del zumbador
int frecuencia = 500; // frecuencia correspondiente a la nota La
void setup() {
pinMode(Pirpin, INPUT);
lcd.init();
lcd.backlight();  
}
void loop() {
int value=digitalRead(Pirpin);

if(value==HIGH){
contar=contar+1;
lcd.clear();
lcd.setCursor(0,0);
lcd.print(contar);
}
else if(contar==10){
tone(pinzumbador,frecuencia); // inicia el zumbido 
delay(600);               // esperar 600 milisegundos
noTone(pinzumbador); // inicia el zumbido
delay(600);               // esperar segundos  
}
}
