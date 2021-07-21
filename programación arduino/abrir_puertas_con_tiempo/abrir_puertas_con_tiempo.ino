#include <Wire.h> 
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,16,2); 
//****************servomotor****************
#include <Servo.h>//incluimos la libreria para poder controlar el servo
Servo servoMotor;//declaramos la variable para controlar el servo
//***************RFID************
#include <SPI.h>      // incluye libreria bus SPI
#include <MFRC522.h>      // incluye libreria especifica para RFID

#define RST_PIN  9      // constante para referenciar pin de reset
#define SS_PIN  10      // constante para referenciar pin de slave select

MFRC522 mfrc522(SS_PIN, RST_PIN); // crea objeto mfrc522 enviando pines de slave select y reset

byte LecturaUID[4];         // crea array para almacenar el UID leido
byte Usuario1[4]= {0xC6, 0xFE, 0xE5, 0x1A} ;    // UID de tarjeta leido en programa 1
byte Usuario2[4]= {0x06, 0x76, 0x25, 0xD9} ;    // UID de llavero leido en programa 1
//**************LCD***********************

RTC_DS1307 RTC;
int b, u, a;
int c=1;
//***********************ultrasonico¨¨¨¨¨¨¨¨¨¨¨¨¨¨
int Trigger=8;
int Echo =7;
long Sensor;
long Distancia;
//*************sonido***********+
int pinzumbador = 6; // pin del zumbador
int frecuencia = 1048; // frecuencia correspondiente a la nota
int frecuencia2 = 277; // frecuencia correspondiente a la nota
void setup () {
servoMotor.attach(3);//iniciamos el servo para que empiece a trabajar con el pin 3  
lcd.init();
lcd.backlight();
lcd.home();
 
Wire.begin(); // Inicia el puerto I2C
RTC.begin(); // Inicia la comunicaci¢n con el RTC
//RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(14, OUTPUT);

 Serial.begin(9600);     // inicializa comunicacion por monitor serie a 9600 bps
 SPI.begin();        // inicializa bus SPI
 mfrc522.PCD_Init();     // inicializa modulo lector
pinMode(Trigger, OUTPUT);
pinMode(Echo, INPUT);
digitalWrite(Trigger, LOW);

pinMode(5, OUTPUT);


}
void horario(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
lcd.clear();
lcd.setCursor(0,0); 
lcd.print("PUERTA CERRADA"); 
lcd.setCursor(0,1);
lcd.print("Tiempo ");
lcd.print(now.hour());
lcd.print(":");
lcd.print(now.minute());
lcd.print(":");
lcd.print(now.second());
servoMotor.write(0);//desplazamos
delay(1000);
}

void horario2(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
lcd.clear();
lcd.setCursor(0,0); 
lcd.print("PUERTA ABIERTA"); 
lcd.setCursor(0,1);
lcd.print("Tiempo ");
lcd.print(now.hour());
lcd.print(":");
lcd.print(now.minute());
lcd.print(":");
lcd.print(now.second());
servoMotor.write(90);//desplazamos
delay(1000);
}

void loop(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC
int a=now.minute();
if(a==38){
c=0;
lcd.clear();
horario2();
lcd.setCursor(0,0);  
lcd.clear();
lcd.print("PUERTA ABIERTA"); 
lcd.setCursor(0,1);
lcd.print("Fecha ");
lcd.print(now.year());
lcd.print("/");
lcd.print(now.month());
 lcd.print("/");
lcd.print(now.day());
lcd.print(" ");
servoMotor.write(90);//desplazamos
digitalWrite(4, HIGH);
digitalWrite(14, LOW);
digitalWrite(2, LOW);
delay(1000);
}
else if(a==9){
c=0;
lcd.clear();
horario2();
lcd.setCursor(0,0);  
lcd.clear();
lcd.print("PUERTA ABIERTA");
lcd.setCursor(0,1);
lcd.print("Fecha ");
lcd.print(now.year());
lcd.print("/");
lcd.print(now.month());
 lcd.print("/");
lcd.print(now.day());
lcd.print(" ");  
servoMotor.write(90);//desplazamos
digitalWrite(4, HIGH);
digitalWrite(14, LOW);
digitalWrite(2, LOW);
delay(1000);
}
else if(a==5){
c=0;
lcd.clear();
horario2();
lcd.setCursor(0,0);  
lcd.clear();
lcd.print("PUERTA ABIERTA");
lcd.setCursor(0,1);
lcd.print("Fecha ");
lcd.print(now.year());
lcd.print("/");
lcd.print(now.month());
 lcd.print("/");
lcd.print(now.day());
lcd.print(" ");
servoMotor.write(90);//desplazamos
digitalWrite(4, HIGH);
digitalWrite(14, LOW);
digitalWrite(2, LOW);
delay(1000); 
}
else if(a==41){
c=0;
lcd.clear();
horario2();
lcd.setCursor(0,0); 
lcd.clear(); 
lcd.print("PUERTA ABIERTA");
lcd.setCursor(0,1);
lcd.print("Fecha ");
lcd.print(now.year());
lcd.print("/");
lcd.print(now.month());
 lcd.print("/");
lcd.print(now.day());
lcd.print(" ");
servoMotor.write(90);//desplazamos
digitalWrite(4, HIGH);
digitalWrite(14, LOW);
digitalWrite(2, LOW);
delay(1000);
}
else if(c==1){
lcd.clear();
horario();
lcd.clear();
lcd.setCursor(0,0); 
lcd.print("PUERTA CERRADA");
lcd.setCursor(0,1);
lcd.print("Fecha ");
lcd.print(now.year());
lcd.print("/");
lcd.print(now.month());
 lcd.print("/");
lcd.print(now.day());
lcd.print(" ");
servoMotor.write(0);//desplazamos
 digitalWrite(5, LOW); 
digitalWrite(4, LOW);
digitalWrite(14, HIGH);
digitalWrite(2, LOW);
delay(1000);
}
//***************ultrasonico**********+
else if(u==1){
 lcd.clear();
 servoMotor.write(0);//desplazamos
  lcd.setCursor ( 0, 0);
 lcd.print("Aplicarse Gel");
  lcd.setCursor ( 0, 1);
 lcd.print("Cm:");
 lcd.setCursor (3, 1);
 lcd.print(Distancia);
 delay(500);
 digitalWrite(8, HIGH);
 delayMicroseconds(10);
 digitalWrite(8, LOW);
 Sensor=pulseIn(7, HIGH);
 Distancia=Sensor/69;
 delay(500);
 digitalWrite(5, LOW);
digitalWrite(4, LOW);
digitalWrite(14, HIGH);
digitalWrite(2, LOW);

  if(Distancia<=50){
  lcd.clear();
  lcd.setCursor ( 0, 0);
  lcd.print(" Dispensando");
  lcd.setCursor ( 0, 1);
  lcd.print("    Gel");
  digitalWrite(5, HIGH);
  delay(5000);
  u=0;
  c=1; 
  
 }
}

//*************** RFID******************
if ( ! mfrc522.PICC_IsNewCardPresent())   // si no hay una tarjeta presente
    return;           // retorna al loop esperando por una tarjeta
  
if ( ! mfrc522.PICC_ReadCardSerial())     // si no puede obtener datos de la tarjeta
    return;           // retorna al loop esperando por otra tarjeta
    
 Serial.print("UID:");       // muestra texto UID:
 for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
 if (mfrc522.uid.uidByte[i] < 0x10){   // si el byte leido es menor a 0x10
 Serial.print(" 0");       // imprime espacio en blanco y numero cero
        }
else{           // sino
Serial.print(" ");        // imprime un espacio en blanco
          }
Serial.print(mfrc522.uid.uidByte[i], HEX);    // imprime el byte del UID leido en hexadecimal
LecturaUID[i]=mfrc522.uid.uidByte[i];     // almacena en array el byte del UID leido      
          }
          
Serial.print("\t");         // imprime un espacio de tabulacion             
                    
if(comparaUID(LecturaUID, Usuario1)){    // llama a funcion comparaUID con Usuario1lcd.clear();
lcd.setCursor(0,0); 
lcd.clear();
lcd.print("ACCES0 PERMITIDO"); 
servoMotor.write(90);//desplazamos
tone(pinzumbador,frecuencia2); // inicia el zumbido
delay(300);
noTone(pinzumbador); // lo detiene a los dos segundos
delay(200);
tone(pinzumbador,frecuencia); // inicia el zumbido
delay(400);
noTone(pinzumbador); // lo detiene a los dos segundos
delay(300);
lcd.clear();
lcd.setCursor(0,0); 
lcd.print("PUERTA ABIERTA"); 
lcd.setCursor(0,1); 
lcd.print("1.min"); 
digitalWrite(4, HIGH);
digitalWrite(14, LOW);
delay(10000);
lcd.clear();
lcd.setCursor(0,0); 
lcd.print("PUERTA CERRADA"); 
servoMotor.write(0);//desplazamos
delay(500);
c=0;
u=1;
}
else{        
lcd.clear();
lcd.setCursor(0,0);  
lcd.print("ACCESO DENEGADO"); 
servoMotor.write(0);//desplazamos
digitalWrite(4, LOW);
digitalWrite(14, HIGH);
digitalWrite(2, HIGH);
tone(pinzumbador,frecuencia); // inicia el zumbido
delay(900);
noTone(pinzumbador); // lo detiene a los dos segundos
delay(1000);
c=1;
}
 
}
                            
//*****************************1***********************
boolean comparaUID(byte lectura[],byte usuario[]) // funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){    // bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])        // si byte de UID leido es distinto a usuario
    return(false);          // retorna falso
  }
  return(true);           // si los 4 bytes coinciden retorna verdadero
}

//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨2¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
