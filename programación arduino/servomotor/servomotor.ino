#include <Servo.h>//incluimos la libreria para poder controlar el servo
Servo servoMotor;//declaramos la variable para controlar el servo

void setup() {
servoMotor.attach(9);//iniciamos el servo para que empiece a trabajar con el pin 9
}

void loop() {
int movimiento=analogRead(A0)/5;//configuramos la variable movimiento con el potenciometro 
servoMotor.write(movimiento);//desplazamos la pocision con con el potenciometro
}
