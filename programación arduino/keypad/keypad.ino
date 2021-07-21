#include <Keypad.h>     // importa libreria Keypad
#include <Adafruit_NeoPixel.h> //incluimos la libreria para los neopixeles 
#define pin 11 //nombramos pin  al pin 11 del arduino
#define numpixels 7 //escribimos la cantidad de neopixeles 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numpixels, pin, NEO_GRB + NEO_KHZ800); 
//le damos todos las reglas a la palabra neopixeles 
const int Pirpin=12; //nombramos pirpin al pin 12 de arduino 
int   PirState=LOW; //tenemos un estado en bajo de pirstate
int val=0; //val tiene un valor de 0
double movimiento; //movimiento almacena variables no enteras 

#include <LiquidCrystal_I2C.h> //incluimos la libreria i2c
#include <Keypad.h> //incluimos la libreria keypad 
LiquidCrystal_I2C lcd(0x27 ,16,2);
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas

int pinzumbador = 10; // pin del zumbador
int frecuencia = 500; // frecuencia correspondiente a la nota La
int a=1;//variable entera 
int c=0;//variable entera 
 


const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

 

byte pinesFilas[FILAS] = {9,8,7,6};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines correspondientes a las columnas

 

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

 

char TECLA;       // almacena la tecla presionada
char CLAVE[7];        // almacena en un array 6 digitos ingresados
char CLAVE_MAESTRA[7] = "123456";   // almacena en un array la contraseña maestra
byte INDICE = 0;      // indice del array

 

  
void setup()
{
 Serial.begin(9600);      // inicializa comunicacion serie
lcd.init(); //iniciamos el lcd
lcd.backlight();  //encendemos el lcd
pixels.begin();//inicimamos los RGB
pinMode(Pirpin, INPUT);
}

 

void loop(){
  if(a==1){ //sentecia if 
lcd.setCursor(0,0);// se establece el cursor 
lcd.print("ALARMA"); //nos muestra la palabra "ALARMA"
lcd.setCursor(0,1);//se establece el cursor 
lcd.print("Bienvenidos");//nos muestra la palabra "Bienvenidos"
delay(1000);//retraso de tiempo de 1 segundo 
lcd.clear();//limpiamos el lcd 
a=2; //establecemos un valor a una variable
c=3; //establecemos un valor a una variable
}
  
if(a==2){ //sentencia if 
lcd.setCursor(0,0); //establecemos el cursor 
lcd.print("Ingrese");//nos muestra la palabra "ingrese"
lcd.setCursor(0,1);//establecemo el cursor 
lcd.print("contrasena");//nos muestra la palabra "contraseña
delay(2000);//un retraso de 2 segudos 
lcd.clear();//limpia el lcd
a=3;} //establecemos un valor a una variable
 
 if(a==3){
  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  if (TECLA)        // comprueba que se haya presionado una tecla
  {
    CLAVE[INDICE] = TECLA;    // almacena en array la tecla presionada
    INDICE++;       // incrementa indice en uno
    lcd.print(TECLA);    // envia a monitor serial la tecla presionada
  }

 

  if(INDICE == 6)       // si ya se almacenaron los 6 digitos
  {
    if(!strcmp(CLAVE, CLAVE_MAESTRA)){   // compara clave ingresada con clave maestra
      lcd.println(" Correcta");  // imprime la palabra "correcta"
        INDICE = 0;//tiene un valor de 0
        delay(1000);//tiene un retraso de 1 s
        lcd.clear();//limpia la lcd
        c=1;//la variable c tiene un valor de 1
    }
    else{//else si no se cumple la condicion 
      lcd.println(" Incorrecta");  // imprime la palabra "incorrecta" 
        INDICE = 0;//indice tiene un valor de 0
        delay(1000);//tiene un retraso de 1 segundo 
        lcd.clear();//limpia la lcd
        c=2;//nombra a c un valor de 2
    }
  }
}
 if(c==1){//setencia if
movimiento=analogRead(A0/270.27)*(5.0/1023.0);//configuramos la variable movimiento con el potenciometro


if(movimiento<=2.55){//setencia if
delay(200);//retraso de tiempo 
int value=digitalRead(Pirpin);

if(value==HIGH){ //setencia if
lcd.clear();//limpiamos la lcd
lcd.setCursor(0,0);//establecemos el cursor 
lcd.print("Hay");// imprime la palabra "Hay" 
lcd.setCursor(0,1);//establecemos el cursor 
lcd.print("personas");// imprime la palabra "Persona" 
for(int i=0; i<7; i++){ //bucle for
pixels.setPixelColor(i, 0,255,0);//RGB
pixels.show();  
}

}
if(value==LOW){//setencia if
lcd.clear();//limpiamos la lcd
lcd.setCursor(0,0);//establecemos el cursor 
lcd.print("No hay");// imprime la palabra "no hay" 
lcd.setCursor(0,1);//establecemos el cursor 
lcd.print("personas");// imprime la palabra "personas " 
for(int i=0; i<7; i++){ //bucle for
pixels.setPixelColor(i, 0,0,0);//RGB
pixels.show(); 
}
}
}
else if(movimiento>=2.5511){//setencia else if
delay(200); //retraso de tiempo 
int value=digitalRead(Pirpin);

if(value==HIGH){//setencia if
lcd.clear();//limpiamos la lcd
lcd.setCursor(0,0);//establecemos el cursor 
lcd.print("Hay");// imprime la palabra "hay" 
lcd.setCursor(0,1);//establecemos el cursor 
lcd.print("personas");// imprime la palabra "personas" 
for(int i=0; i<7; i++){ //bucle for
pixels.setPixelColor(i, 255,102,0);//RGB
pixels.show();  
tone(pinzumbador,frecuencia); // inicia el zumbido
delay(200);               // esperar 2 milisegundos
noTone(pinzumbador); // inicia el zumbido
delay(100);               // esperar 100 milisegundos 
}
for(int i=0; i<7; i++){ //bucle for
pixels.setPixelColor(i, 201,60,32);//RGB
pixels.show();  
tone(pinzumbador,frecuencia); // inicia el zumbido
delay(200);               // esperar 200 milisegundos
noTone(pinzumbador); // inicia el zumbido
delay(100);               // esperar 100 milisegundos 
}
}
else if(value==LOW){//setencia else if
lcd.setCursor(0,0);//establecemos el cursor 
lcd.print("No hay");// imprime la palabra "no hay" 
lcd.setCursor(0,1);//establecemos el cursor 
lcd.print("personas");// imprime la palabra "personas" 
for(int i=0; i<7; i++){//bucle for 
pixels.setPixelColor(i, 255,0,0);//RGB
pixels.show(); 
}

}  
}
}

if(c==2){//setencia if

lcd.setCursor(0,0);//establecemos el cursor 
lcd.print("alarma");// imprime la palabra "alarma" 
lcd.setCursor(0,1);//establecemos el cursor 
lcd.print("desactivada");// imprime la palabra "desactivada" 
for(int i=0; i<7; i++){//bucle for
pixels.setPixelColor(i, 0,0,0);//RGB
pixels.show(); 
}
delay(3000);//retraso de tiempo 
lcd.clear();//limpiamos la lcd
a=1;
}
}  
