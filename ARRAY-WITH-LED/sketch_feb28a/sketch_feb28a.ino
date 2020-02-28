// 5 leds
// 5 pins array 0,1,2,3,4
// resistor 220 ohm


int ledArray[] = {2,3,4,5,6};
int delayTime = 150;


void setup() {
  // put your setup code here, to run once:

  for (int i=0; i<10; i++){
    pinMode(ledArray[i], OUTPUT);
  }

}

// infinite loop
void loop() {
  // turn on LED on from 0-5
    for(int i = 0; i <= 4; i++){   //for(int i = 0; i <= 1; i++) will turn led 1 and 2 , staring in 0 to 1, so pin 2 and 3 of the array
    digitalWrite(ledArray[i], HIGH);
    delay(delayTime);
   
  }
 //turn LEDs off from 5-0
   for (int i= 4; i >= 0; i--){   //for (int i= 0; i >= 0; i--) so the loop will turn on and off led 1, position 0 = pin 2 
    digitalWrite(ledArray[i], LOW);
    delay(delayTime);
  }

}
