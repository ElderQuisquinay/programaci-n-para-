#include <LiquidCrystal_I2C.h>

// aqui se configuran los pines para la pantalla
LiquidCrystal_I2C lcd(0x27 ,16,2);

int Trigger=8;
int Echo =7;
long Sensor;
long Distancia;

void setup() {
lcd.init();
lcd.backlight();
lcd.home();
pinMode(Trigger, OUTPUT);
pinMode(Echo, INPUT);
digitalWrite(Trigger, LOW);
}

void loop() {
digitalWrite(8, HIGH);
delayMicroseconds(10);
digitalWrite(8, LOW);
Sensor=pulseIn(7, HIGH);
Distancia=Sensor/69;
  lcd.clear();
  lcd.setCursor ( 0, 0);
  lcd.print(Distancia);
  delay(500);
  
}
