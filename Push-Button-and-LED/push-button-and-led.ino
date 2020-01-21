void setup()
{
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  // if the button it is pressed
  if (digitalRead(2) == HIGH) {
    // turn LED.
    digitalWrite(10, HIGH);
  } else {
    // turn off LED.
    digitalWrite(10, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
