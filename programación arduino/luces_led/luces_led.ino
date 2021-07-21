//Declaramos los leds

int LED1 = 3;

int LED2 = 4;

int LED3 = 5;

int LED4 = 6;

int LED5 = 7;

int LED6 = 8;

int LED7 = 9;

int LED8 = 10;



//Las variables que usaremos para el silencio

int Valor;

int Valor1;

int Valor2;

int Valor3;

int Valor4;



//Configuramos los pines y el serial para poder visualizar la entrada analogica

void setup (){

 Serial.begin(9600);

 pinMode(LED1,OUTPUT);

 pinMode(LED2,OUTPUT);

 pinMode(LED3,OUTPUT);

 pinMode(LED4,OUTPUT);

 pinMode(LED5,OUTPUT);

 pinMode(LED6,OUTPUT);

 pinMode(LED7,OUTPUT);

 pinMode(LED8,OUTPUT);

}



void loop (){

  //Leemos el valor

 Valor = analogRead(A0);

 //Transferimos los valores para saber cual era el estado anterior

 Valor4 = Valor3;

 Valor3 = Valor2;

 Valor2 = Valor1;

 Valor1 = Valor;



//Visualizamos los valores en Serial Monitor

 Serial.print("Valor: ");

 Serial.print(Valor);

 Serial.print("\t Valor1: ");

 Serial.print(Valor1);

 Serial.print("\t Valor2: ");

 Serial.print(Valor2);

 Serial.print("\t Valor3: ");

 Serial.print(Valor3);

 Serial.print("\t Valor4: ");

 Serial.println(Valor4);

 

 //Condicionamos que si el programa lee 4 veces seguidas 0 que se apagen los leds, si no ponemos esto los leds parpadearan mucho

if (Valor1+Valor2+Valor3+Valor4==0){

  digitalWrite(LED1,LOW);

  digitalWrite(LED2,LOW);

  digitalWrite(LED3,LOW);

  digitalWrite(LED4,LOW);

  digitalWrite(LED5,LOW);

  digitalWrite(LED6,LOW);

  digitalWrite(LED7,LOW);

  digitalWrite(LED8,LOW);

}

//Encendemos los leds segun el valor de entrada. En este caso la salida de mi pc como mucho me llega a 400 asi que lo dividimos entre ocho leds.

else{

 if (Valor>0){

   digitalWrite(LED1, HIGH);

 }

 else{

   digitalWrite(LED1, LOW);

 }



 if (Valor>50){

   digitalWrite(LED2, HIGH);

 }

 else{

   digitalWrite(LED2, LOW);

 }

 if (Valor>100){

   digitalWrite(LED3, HIGH);

 }

 else{

   digitalWrite(LED3, LOW);

 }



 if (Valor>150){

   digitalWrite(LED4, HIGH);

 }

 else{

   digitalWrite(LED4, LOW);

 }



 if (Valor>200){

   digitalWrite(LED5, HIGH);

 }

 else{

   digitalWrite(LED5, LOW);

 }



 if (Valor>250){

   digitalWrite(LED6, HIGH);

 }

 else{

   digitalWrite(LED6, LOW);

 }



 if (Valor>300){

   digitalWrite(LED7, HIGH);

 }

 else{

   digitalWrite(LED7, LOW);

 }



 if (Valor>350){

   digitalWrite(LED8, HIGH);

 }

 else{

   digitalWrite(LED8, LOW);

}

}

} 
