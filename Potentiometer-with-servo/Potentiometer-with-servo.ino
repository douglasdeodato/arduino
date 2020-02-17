// brow cable ground
// red cable 5v
// yellow pin of your choice.

// potentiometer por a1 and positive 5v and ground.

// inclui bibilioteca do servomotor
#include <Servo.h> 

// define pinos dos servos
#define pinServ1 10


// define as portas dos potenciometros
#define pot1 A1


// nomeia os servos
Servo serv1;

// cria as variavies dos angulos de cada motor
int motor1;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 5000;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  serv1.attach(pinServ1);

  
}

void loop(){

  // leitura dos potenciometros
  // https://www.arduino.cc/reference/en/language/functions/math/map/
  //// converts reading from potentiometer to an output value in degrees of rotation that the servo can understand 
  motor1 = map(analogRead(pot1),0,1023,0,180); 


  // posicionamento dos potenciometros 
  serv1.write(motor1);
  

   if ((millis() - mostradorTimer) >= intervaloMostrador) {

  // envio para o monitor serial do posicionamentos dos motores
  Serial.println("**********************************************");
  
  Serial.print("Pot1:");
  Serial.print(analogRead(pot1));
  Serial.print(" Angulo Motor1:");
  Serial.println(motor1);



  mostradorTimer = millis();
  }

  // tempo de espera para recomeçar
  delay(100);

}
