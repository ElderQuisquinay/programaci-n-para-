#include <Stepper.h> //incluimos la libreria del motor stepper
Stepper motor1(2048, 11, 9, 10, 8); //paso completo  4*8*64=2048 pasos para la una revolucion
  int a;
  int b;
   int c;
void setup() {
  motor1.setSpeed(3); //RPM revoluciones por minuto
  pinMode(5, INPUT); //pin de emtrada
  pinMode(4, INPUT); //pin de emtrada
}
 
void loop() {
  int estado=digitalRead(5);/*Lee el valor de un pin digital 
  especificado, ya sea HIGHo LOW valor de 0 y 1*/
  int estado1=digitalRead(4);/*Lee el valor de un pin digital 
  especificado, ya sea HIGHo LOW valor de 0 y 1*/
  if(estado==1){ //sentecia if
  int pasos=a;   //declaramos paso con el valor de la variable "a"
  a=c+512; //le aplicamos un valor a la letra "a"
  motor1.step(pasos); //movimiento con las cantidad de pasos
  }
  else if(estado1==1){ //sentecia if
  b=c-512; //le declaramos un valor a la letra "b"
  int pasos=b; //paso es igual a "b"
  motor1.step(pasos); //movimiento con las cantidad de pasos
  }
  }
