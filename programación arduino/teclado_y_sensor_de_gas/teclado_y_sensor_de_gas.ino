#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(0x27 ,16,2);
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
const byte FILAS=4;
const byte COLUMNAS=4;
char keys[FILAS][COLUMNAS]={
 {'7','8','9','d'},
 {'4','5','6','c'}, 
 {'1','2','3','b'},
 {'*','0','#','a'}
};
byte pinesFilas[FILAS]={9,8,7,6};
byte pinesColumnas[COLUMNAS]={5,4,3,2};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
char TECLA;
char TECLA1;
char CLAVE[7];
char CLAVE1[3];
char CLAVE_MAESTRA1[3]="98";
char CLAVE_MAESTRA[7]="123456";
byte INDICE=0;
byte INDICE1=0;
int b=0;

void setup() {
lcd.init();
lcd.backlight();
}

void loop() {
TECLA=teclado.getKey();
if(TECLA){
CLAVE[INDICE]= TECLA;
INDICE++;
lcd.clear();
lcd.setCursor(0,0);
lcd.print(TECLA);}

else if(INDICE==6){
if (!strcmp(CLAVE, CLAVE_MAESTRA)){
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Acceso Autorizaso");
b=12;
INDICE= 0;
delay(1000);
}
else{ 
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Acceso denegado");
INDICE= 0;
}
}
else if(b==12){
if(INDICE==2){
if(!strcmp(CLAVE, CLAVE_MAESTRA1)){
lcd.clear();
lcd.setCursor(0,0);
lcd.print(TECLA);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Activar presione 1");  
lcd.clear();
lcd.setCursor(0,1);
lcd.print("desactivar presione 1"); 

}
}
}
}
