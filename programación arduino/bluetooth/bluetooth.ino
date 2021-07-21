
int ledPin=12;
int ledPin1=11;
int ledPin2=10;
int state=0;
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600);
}

void loop() {
 state=Serial.read();

if(state=='0'){
  digitalWrite(ledPin, LOW);
  Serial.println("LED ROJO: off");
}
else if(state=='1'){
digitalWrite(ledPin, HIGH);
Serial.println("LED ROJO: on");
}
else if(state=='2'){
  digitalWrite(ledPin1, LOW);
  Serial.println("LED VERDE: off");
}
else if(state=='3'){
digitalWrite(ledPin1, HIGH);
Serial.println("LED VERDE: on");
}
else if(state=='4'){
  digitalWrite(ledPin2, LOW);
  Serial.println("LED AZUL: off");
}
else if(state=='5'){
digitalWrite(ledPin2, HIGH);
Serial.println("LED AZUL: on");
}

}
