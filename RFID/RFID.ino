/*

Este código reconhece um cartão e acende LEDs

*/

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
 
void setup() 
{
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init();   
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
 
void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  Serial.print("Identificação do cartao:");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
 
  if (conteudo.substring(1) == "44 46 00 22") //cartao 1 master  vermelho
  {
    Serial.println("red led on");
    Serial.println();
    digitalWrite(7, HIGH); // ativa led vermelho
    delay(500);           // espera 3 segundos
    digitalWrite(7, LOW);  // desativa led vermelho
    delay(500); 
    digitalWrite(7, HIGH); 
    delay(500);           
    digitalWrite(7, LOW);
    delay(500); 
    digitalWrite(7, HIGH);
    delay(500);          
    digitalWrite(7, LOW);
  }  

   if (conteudo.substring(1) == "C9 7C E6 B9") //cartao 2 verde
  {
    Serial.println("green led on");
    Serial.println();
    digitalWrite(6, HIGH); // ativa led verde
    delay(500);                 // espera 3 segundos
    digitalWrite(6, LOW); // desativa led verde
    delay(500); 
    digitalWrite(6, HIGH); 
    delay(500);          
    digitalWrite(6, LOW);
    delay(500); 
    digitalWrite(6, HIGH); 
    delay(500);           
    digitalWrite(6, LOW);
  }  

   if (conteudo.substring(1) == "9A 42 65 19") //cartao 3 amarelo
  {
    Serial.println("yellow led on");
    Serial.println();
    digitalWrite(5, HIGH); // ativa led amarelo
    delay(500);           // espera 3 segundos
    digitalWrite(5, LOW);  // desativa led amarelo
    delay(500); 
    digitalWrite(5, HIGH); 
    delay(500);          
    digitalWrite(5, LOW);
    delay(500); 
    digitalWrite(5, HIGH); 
    delay(500);          
    digitalWrite(5, LOW);
  }  
}
