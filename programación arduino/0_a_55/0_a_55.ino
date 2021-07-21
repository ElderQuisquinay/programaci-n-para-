#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27 ,16,2);

void setup() {
lcd.init();
lcd.backlight();
}

void loop() {
for(int a=0;  a<55; a++){
if(a>50){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Electonica Kinal");
delay(2000);
}
else{
lcd.clear();
lcd.setCursor(0,0);
lcd.print(a);
delay(500);
}
}
}
