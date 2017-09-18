/*
 by-siddharth jain
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 mot1 to pin 5 & 6  for rotation
 mot2 to pin 3 & 4  to pull the rubber-band
 servo1 for throw
 servo2 to release ball
 */
 
#include <Servo.h>
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
Servo myservo1;
Servo myservo2;
int maximumRange = 10; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int k=0;
int pos=90; 
int pos1,pos2,pos3; 
void setup() 
{
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
  myservo1.attach(9);
  myservo2.attach(10);
  
}

void loop()
{
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
  if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");

 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);

 }
  if(distance<20 && distance != -1)
{ 
  for(pos1 = 0; pos1 <= 90; pos1 += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos' 
    delay(3);                       // waits 15ms for the servo to reach the position 
  } 
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  delay(2000);//change here.................................................................
   digitalWrite(3,LOW);
   delay(5000); 
  for(pos1 = 90; pos1>=0; pos1-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo1.write(pos1);              // tell servo to go to position in variable 'pos' 
    delay(3);                       // waits 15ms for the servo to reach the position 
  }
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  delay(2000);//change here.................................................................
  digitalWrite(4,LOW); 
  delay(2000);
}
 if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    
    pos2=Serial.read();
    if(pos2==5)
    {
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
    }
    else if(pos2==10)
    {
      digitalWrite(6,HIGH);
      digitalWrite(5,LOW);
    } 
    else if(pos2==15 || pos2==20)
    {
      digitalWrite(6,LOW);
      digitalWrite(5,LOW);
      if(pos2==20)
      k=5;
    } 
    

 

  if (k==5){
for(pos3 = 0; pos3 <= 90; pos3 += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos3);              // tell servo to go to position in variable 'pos' 
    delay(3);                       // waits 15ms for the servo to reach the position 
  }for(pos3 = 90; pos3 >= 0; pos3 -= 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo2.write(pos3);              // tell servo to go to position in variable 'pos' 
    delay(3);                       // waits 15ms for the servo to reach the position 
  }
  k=0;
  
  }
} 
} 

