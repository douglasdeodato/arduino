//infinite loop the servo never will stop.

// brow cable ground
// red cable 5v
// yellow pin of your choice.

#include <Servo.h>
Servo servo;
int angle = 10;

void setup() {
  servo.attach(8);
  servo.write(angle);
  Serial.begin(9600);
}

void loop() 
{   
 // scan from 0 to 180 degrees
  for(angle = 10; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(1);  //speed 
    Serial.print(angle); 
    Serial.println(" degree"); 
    digitalWrite(2, LOW); // turn off led              
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--)    
  {                                
     servo.write(angle);           
     delay(133);  //speed    
     Serial.print("Moving back to: ");
     Serial.print(angle); 
     Serial.println(" degree with a 133 delay");  
     digitalWrite(2, HIGH); // turn on led
  }  
}
