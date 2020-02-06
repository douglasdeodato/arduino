const uint8_t   LED_OFF         =  LOW;     
const uint8_t   LED_ON          = HIGH;    

const uint8_t   pinGREEN_BUTTON       = 2;
const uint8_t   pinRED_BUTTON         = 3;
const uint8_t   pinYELLOW_BUTTON      = 4;

const uint8_t   pinGREEN_LED          = 10;
const uint8_t   pinRED_LED            = 9;
const uint8_t   pinYELLOW_LED         = 8;

void setup()

{
  pinMode(pinGREEN_BUTTON, INPUT_PULLUP);
  pinMode(pinRED_BUTTON, INPUT_PULLUP);
  pinMode(pinYELLOW_BUTTON, INPUT_PULLUP);
  pinMode(pinGREEN_LED, OUTPUT);
  pinMode(pinRED_LED, OUTPUT);
  pinMode(pinYELLOW_LED, OUTPUT);
}

void loop()
{
  if (digitalRead(pinGREEN_BUTTON) == LED_OFF){
    digitalWrite(pinGREEN_LED, LED_ON);
  }
  else if (digitalRead(pinRED_BUTTON) == LED_OFF) {
    digitalWrite(pinRED_LED, LED_ON);
  }
   else if (digitalRead(pinYELLOW_BUTTON) == LED_OFF) {
    digitalWrite(pinYELLOW_LED, LED_ON);
  }
  else {
    // turn off LED.
    digitalWrite(pinGREEN_LED,LED_OFF);
    digitalWrite(pinRED_LED, LED_OFF);
    digitalWrite(pinYELLOW_LED, LED_OFF);
  }
}
