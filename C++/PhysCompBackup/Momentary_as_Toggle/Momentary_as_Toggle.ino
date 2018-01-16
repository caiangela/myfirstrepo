/*This is to test using pushbuttons as 'toggleswitches'
 *so press one time == high, two times == low, three times == high...
 *I'm considering using modulo, so PressedTimes%2 == 0 then high*/
 
const int rLED = 5;
const int rButtonPin = A1;
int rButtonVal;
boolean ru

void setup() {  
 pinMode (rLED, OUTPUT);
 pinMode (rButtonPin, INPUT);
 digitalWrite(rLED, LOW);
}

void loop() {
    
  rButtonVal = digitalRead(rButtonPin);
  
  if (rButtonVal == HIGH){  
  digitalWrite(rLED, HIGH); 
  delay(100);
  }
}
