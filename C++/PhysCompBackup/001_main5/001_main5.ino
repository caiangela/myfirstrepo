int button1Pin = A2;
int button1State = LOW;
int button2Pin = A1;
int button2State = LOW;
int button3Pin = A0;
int button3State = LOW;
int button4Pin = A5;
int button4State = LOW;
int button5Pin = A4;
int button5State = LOW;
int button6Pin = A3;
int button6State = LOW;

int n = 1;

#include "LedMatrixObject.h"
LedMatrixObject *led = new LedMatrixObject(2, 3, 4, 5, 6, 7, 8, 9);

unsigned char FistWithGap[16][16] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1},  
  {1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1},
  {1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},//x
  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//x
  {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//...............................x, x, x
/*                               1, 1, 0
 *                               1, 0, 0
 */
};

/*unsigned char FistHint[16][16] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1},  
  {1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1},
  {1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1},//x
  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},//x
  {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//...............................x, x, x
/*                               1, 1, 0
 *                               1, 0, 0*
 *                               originally used this as a highlighted hint
 *                               but it didn't appear very readable 
 *                               so turned single leds on instead
*/

unsigned char ThumbUp[16][16] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
  {1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
  {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
  {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},//x
  {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},//x
  {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//...............................x, x, x
/*                               1, 1, 0
 *                               1, 0, 0*/
};

const int buzzerPin = 13;
const int songLength = 9;
char notes[] = "cf egfcad "; // a short melody from communism anthem
int beats[] = {2,4,1,2,2,2,2,2,4};
int tempo = 113;

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

void setup() {
  pinMode(button5Pin, INPUT);
  button5State = digitalRead(button5Pin);
  button5State = LOW;
  pinMode(buzzerPin, OUTPUT);
}


void loop() {  
   led->setScene(FistWithGap);
   led->draw();
  
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  int button3State = digitalRead(button3Pin);
  int button4State = digitalRead(button4Pin);
  int button5State = digitalRead(button5Pin);
  int button6State = digitalRead(button6Pin);

  int i, duration;
  
if((button1State == HIGH)){   
   led->setScene(FistWithGap);
   led->setLedOn(9,10);
   led->draw();
   tone(buzzerPin, frequency(notes[i]), 4);}
if((button2State == HIGH)){   
   led->setScene(FistWithGap);
   led->setLedOn(9,11);
   led->draw();
   tone(buzzerPin, frequency(notes[i]), 4);}
if((button3State == HIGH)){   
   led->setScene(FistWithGap);
   led->setLedOn(9,12);
   led->draw();
   tone(buzzerPin, frequency(notes[i]), 4);}
if((button4State == HIGH)){   
   led->setScene(FistWithGap);
   led->setLedOn(10,10);
   led->draw();
   tone(buzzerPin, frequency(notes[i]), 4);}
if((button5State == HIGH)){   
   led->setScene(FistWithGap);
   led->setLedOn(10,11);
   led->draw();
   tone(buzzerPin, frequency(notes[i]), 4);}
if((button6State == HIGH)){   
   led->setScene(FistWithGap);
   led->setLedOn(10,12);
   led->draw();
   tone(buzzerPin, frequency(notes[i]), 4);}
   
   if ((button3State == HIGH) && (button5State == HIGH) && (button6State == HIGH)){
    for (n = 1; n > 0; n++){
     led->setScene(FistWithGap);
     led->setLedOn(9,12);
     led->setLedOn(10,11);
     led->setLedOn(10,12);
     led->draw();

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
     for (n = 10000; n > 0; n++){
     led->setLedOff(9,12);
     led->setLedOff(10,11);
     led->setLedOff(10,12);
     led->setScene(ThumbUp);
     led->draw(); }
    }
   }
   } 


