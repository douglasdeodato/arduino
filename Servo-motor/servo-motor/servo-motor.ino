  /*
 Controlling a servo with two Push buttons with Arduino
 when Left  push button is pressed, the servo start moving to the left until it reaches 180( or zero) degrees
 when Right  push button is pressed, the servo start moving to the right until it reaches 180( or zero) degrees
At any instance if the button is released, servo stops

 May 22, 2018 at 01:00 
 Written by Ahmad S. for Robojax.com at Ajax, Ontario, Canada
 Watch video for this code at https://youtu.be/7woqNH_qby4
 This code is taken from http://robojax.com/learn/arduino
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int angle =90;    // initial angle  for servo
int angleStep =5;

#define LEFT 12   // pin 12 is connected to left button
#define RIGHT  2  // pin 2 is connected to right button

void setup() {
  // Servo button demo by Robojax.com
  Serial.begin(9600);          //  setup serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(LEFT,INPUT_PULLUP); // assign pin 12 ass input for Left button
  pinMode(RIGHT,INPUT_PULLUP);// assing pin 2 as input for right button
  myservo.write(angle);// send servo to the middle at 90 degrees
 Serial.println("Robojax Servo Button ");
}

void loop() {
  // Servo button demo by Robojax.com
  while(digitalRead(RIGHT) == LOW){

    if (angle > 0 && angle <= 180) {
      angle = angle - angleStep;
       if(angle < 0){
        angle = 0;
       }else{
      myservo.write(angle); // move the servo to desired angle
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
    
  delay(100); // waits for the servo to get there
  }// while
 // Servo button demo by Robojax.com

  while(digitalRead(LEFT) == LOW){

    // Servo button demo by Robojax.com
    if (angle >= 0 && angle <= 180) {
      angle = angle + angleStep;
      if(angle >180){
        angle =180;
       }else{
      myservo.write(angle); // move the servo to desired angle
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
    
  delay(100); // waits for the servo to get there
  }// 

  
}
