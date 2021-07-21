/*
   -- modulo wifi --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.4.3 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.5.1 or later version;
     - for iOS 1.4.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#include <RemoteXY.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel tira = Adafruit_NeoPixel(7, 6, NEO_GRB + NEO_KHZ800);
// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "Remotexy"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 1515


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,6,0,0,0,105,0,10,24,0,
  2,1,7,7,22,11,28,26,31,31,
  79,78,0,79,70,70,0,2,1,56,
  7,22,11,28,27,31,31,79,78,0,
  79,70,70,0,129,0,10,19,19,6,
  16,108,117,122,32,108,101,100,0,2,
  1,49,39,22,11,27,28,31,31,79,
  78,0,79,70,70,0,129,0,61,20,
  18,6,16,102,111,99,111,0,129,0,
  34,53,10,6,16,108,101,100,115,32,
  114,103,98,0,6,0,22,32,20,20,
  2,26 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t rgb_1_r; // =0..255 Red color value 
  uint8_t rgb_1_g; // =0..255 Green color value 
  uint8_t rgb_1_b; // =0..255 Blue color value 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 8
#define PIN_SWITCH_2 9
#define PIN_SWITCH_3 10


void setup() 
{
  RemoteXY_Init (); 
  tira.begin();
  tira.show(); //deja los pixeles apagados
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?HIGH:LOW);
  if(RemoteXY.switch_3==1){
  for(int i=0; i<7; i++){
  tira.setPixelColor(i, 'r', 'g','b'); //posicion, R, G, B
  tira.show();  
  }
  }
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
