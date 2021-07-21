
#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal_I2C.h>
//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27 ,16,2);
time_t fecha;

int pinzumbador = 13; // pin del zumbador
int frecuencia = 220; // frecuencia correspondiente a la nota La

void setup() {
 setTime(21, 00, 00, 4, 5, 2020);
 

fecha = now();
lcd.init();
lcd.backlight();
} 

void loop() {
int a=minute();
if(a==2){
lcd.setCursor(0,0);
lcd.print("pasaron 2 minutos");
tone(pinzumbador,frecuencia); // inicia el zumbido
delay(2000);
lcd.clear();
noTone(pinzumbador); // lo detiene a los dos segundos
delay(1000);

}
else{
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
delay(1000);
  }
}
