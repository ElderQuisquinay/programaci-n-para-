/* programa N0.2 
Elder Antonio Quisquinay Mazate*/

const byte num1[10]={
  //gfedcba
  0b0111111,//0
  0b0000110,//1
  0b1011011,//2
  0b1001111,//3
  0b1100110,//4
  0b1101101,//5
  0b1111100,//6
  0b0000111,//7
  0b1111111,//8
  0b1100111,//9
};
const byte num2[10]={
  0b0111111,//0
  0b0000110,//1
  0b1011011,//2
  0b1001111,//3
  0b1100110,//4
  0b1101101,//5
  0b1111100,//6
  0b0000111,//7
  0b1111111,//8
  0b1100111,//9
};

int transistor1=9;//DECENAS
int transistor2=10;//UNIDADES
void setup()
{
 pinMode(transistor1, OUTPUT);
 pinMode(transistor2, OUTPUT);
 DDRD=350;
 }
void loop(){
  for(int e=0; e<10; e++){
  
  for(int a=0; a<10; a++){
    
  digitalWrite(transistor1, HIGH);
  digitalWrite(transistor2, LOW); 
  PORTD=num1[a];
  delay(1000);
  digitalWrite(transistor1, LOW);
  digitalWrite(transistor2, HIGH); 
   PORTD=num2[e];
  delay(1000);
 }
}
 }   
