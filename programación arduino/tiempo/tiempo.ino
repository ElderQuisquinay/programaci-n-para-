
#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal_I2C.h>
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27 ,16,2);
time_t fecha;

void setup() {
setTime(15, 02, 45, 4, 5, 2020);
 
  // Obtenemos la fecha actual
 fecha = now();
lcd.init();
lcd.backlight();
} 

void loop() {
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Hora: ");
lcd.print(hour());
lcd.print(":");
lcd.print(minute());
lcd.print(":");
lcd.println(second());
lcd.setCursor(0,1);
lcd.print("fecha: ");
lcd.print(day());
lcd.print("/");
lcd.print(month());
lcd.print("/");
lcd.println(year());
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("LUNES");
delay(2000);
int a=minute();
if(a==3){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("LUAZSNES");
delay(3000);
}
}
