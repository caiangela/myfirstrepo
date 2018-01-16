/*
SparkFun Inventor's Kit 
Example sketch 11

BUZZER

  Use the buzzer to play a song!

  The buzzer in your Inventor's Kit is an electromechanical
  component you can use to make noise. Inside the buzzer is a
  coil of wire and a small magnet. When current flows through 
  the coil, it becomes magnetized and pulls towards the magnet,
  creating a tiny "click". When you do this thousands of times
  per second, you create tones.

  The Arduino has a built-in command called tone() which clicks
  the buzzer at a certain frequency. This sketch knows the
  frequencies of the common notes, allowing you to create songs.
  We're never going to let you down!

Hardware connections:

  The buzzer has two pins. One is positive and one is negative.
  The postitive pin is marked by a "+" symbol on both the top
  and bottom of the buzzer.

  Connect the positive pin to Arduino digital pin 9.
  (Note that this must be a PWM pin.)
  Connect the negative pin to GND.

  Tip: if the buzzer doesn't fit into the breadboard easily,
  try rotating it slightly to fit into diagonal holes.

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
(This sketch was originally developed by D. Cuartielles for K3)
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/

/*
  note  frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz

 http://arduino.cc/en/Tutorial/Tone
*/

const int buzzerPin = 13;
// Length must equal the total number of notes and spaces 

const int songLength = 9;

// Notes is an array of text characters
// space represents a rest (no tone)

char notes[] = "cf egfcad "; // a short melody from communism anthem

int beats[] = {2,4,1,2,2,2,2,2,4};

int tempo = 113;

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
}


void loop() 
{
  int i, duration;
  for (i = 0; i < songLength; i++){
    duration = beats[i] * tempo;  
    if (notes[i] == ' ')  {
      delay(duration);            
    } else {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);
    }
    delay(tempo/10);
  }
  while(true){}//only plays once
}


int frequency(char note) 
{ int i;
  const int numNotes = 8;  
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 220, 494, 523};
  
  for (i = 0; i < numNotes; i++){
    if (names[i] == note) 
    {return(frequencies[i]);
    }
  }
  return(0);  
}
