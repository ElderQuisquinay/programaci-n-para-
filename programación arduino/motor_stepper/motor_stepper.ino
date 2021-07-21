#include <Stepper.h>
const int stepsPerRevolution =200;
Stepper myStepper(stepsPerRevolution, 8,9,10,11);

int stepCount = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
int sensorResding=analogRead(A0); 
int motorSpeed=map(sensorResding, 0, 1023, 0, 10);
if(motorSpeed>0){
myStepper.setSpeed(motorSpeed);
myStepper.step(stepsPerRevolution / 100);
}
}
