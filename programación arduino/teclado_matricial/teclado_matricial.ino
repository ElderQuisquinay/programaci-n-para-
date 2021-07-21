void setup() {
Serial.begin(9600);
}

void loop() {
int adc_MQ=analogRead(14);
float voltaje=adc_MQ*(3.3/4095);
Serial.print("adc:");
Serial.print(adc_MQ);
Serial.print("      voltaje:");
Serial.print(voltaje);
delay(100);
}
