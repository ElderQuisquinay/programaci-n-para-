#include <Servo.h>//incluimos la libreria para poder controlar el servo
Servo servoMotor;//declaramos la variable para controlar el servo
int movimiento=0;
char dezplazamiento;
void setup() {
servoMotor.attach(9);//iniciamos el servo para que empiece a trabajar con el pin 9
Serial.begin(9600);//inicia la comunicacion serial
}

void loop() {
dezplazamiento=Serial.read(); // Obtén el siguiente personaje de bluetooth
if(dezplazamiento=='R') { movimiento=Serial.parseInt(); // Leer valor el valor 
servoMotor.write(movimiento);//desplazamos la pocision con con el potenciometro
 Serial.println (movimiento);
}
else {
}
}
