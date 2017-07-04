#include <Servo.h>

Servo myservoBlue;
Servo myservoYellow;
Servo myservoGreen;
int val;
int  z = 2000; //
int o = -2000;

int posGreen=20; // store servo positions
int posBlue=20;
int posYellow=20;

int averageGreen=0;
int averageBlue=0;
int averageYellow=0;

long seconds=0;

void setup()
{
myservoBlue.attach(9);
myservoYellow.attach(6);
myservoGreen.attach(3);
Serial.begin(9600);
}

void loop()
{
  
if (millis()/1000>seconds){       // will happen every second
  seconds++; // update seconds
  averageBlue   += analogRead(0); // read blue sensor
  averageYellow += analogRead(3); // read yellow sensor
  averageGreen  += analogRead(6); // read green sensor
  
  averageBlue   = averageBlue/2;  // calculate average values
  averageYellow = averageYellow/2;
  averageGreen  = averageGreen/2;
}  
  

int posA=150;
int posB=30;

//blue
val = analogRead(0)-averageBlue;
val = map(val,z, o,0,179);
posBlue += constrain(val,50,140);
posBlue=posBlue/2;
myservoBlue.write(posBlue);
delay(15);

//yellow
val = analogRead(3)-averageYellow;
val = map(val,z, o, 0,179);
posYellow += constrain(val,50,140);
posYellow=posYellow/2;
myservoYellow.write(posYellow);
delay(15);

//green
val = analogRead(6)-averageGreen;
val = map(val,z, o,0,179);
posGreen += constrain(val,50,140);
posGreen=posGreen/2;
myservoGreen.write(posGreen);
delay(15);

}


