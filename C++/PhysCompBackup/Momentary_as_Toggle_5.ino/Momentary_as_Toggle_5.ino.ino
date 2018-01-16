int button5Pin = A5;
int button5State = LOW;
int m;
int n = 0;

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

 
void setup() {
  pinMode(button5Pin, INPUT);
  button5State = digitalRead(button5Pin);
  button5State = LOW;
}

void draw(){
  Serial.begin(9600);
}

void loop() {  
   led->setScene(FistWithGap);
   led->draw();
   
  int newButton5State = digitalRead(button5Pin);
  
   if (newButton5State == HIGH && button5State == LOW){
    if (n == 0){
      led ->setLedOn(14, 14);
      n = 1;
    }
    else{
      led ->setLedOff(14, 14);
      n = 0;      
    }
    button5State = newButton5State;
   }
   }
