void setup()

{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  if (digitalRead(2) == LOW) {
    digitalWrite(10, HIGH);
  }
  else if (digitalRead(3) == LOW) {
    digitalWrite(9, HIGH);
  }
   else if (digitalRead(4) == LOW) {
    digitalWrite(8, HIGH);
  }
  else {
    // turn off LED.
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
  }
}
