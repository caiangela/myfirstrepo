int redButtonPin = A1;
int redLEDPin = 5;
int redButtonState = LOW;
int x = 0;

void setup(){
  pinMode(redLEDPin, OUTPUT);
  pinMode(redButtonPin, INPUT);
  digitalWrite(redLEDPin, LOW);
}

void loop(){
  // Get new button state
  int newRedButtonState = digitalRead(redButtonPin);

  if (newRedButtonState == HIGH && redButtonState == LOW) {
    if (x == 0) {
      // Toggle on
      digitalWrite(redLEDPin, HIGH);
      x = 1;
    } else {
      // Toggle off
      digitalWrite(redLEDPin, LOW);
      x = 0;
    }
  }

  // Update new button state
  redButtonState = newRedButtonState;
}
