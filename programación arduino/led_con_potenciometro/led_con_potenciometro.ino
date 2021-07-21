const int LED=9;
int brillo;
void setup() {
pinMode(LED, OUTPUT);
}

void loop(){
  brillo=analogRead(A0)/5;
  analogWrite(LED,brillo); 
}
