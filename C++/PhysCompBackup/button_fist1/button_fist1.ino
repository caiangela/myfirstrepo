#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

//defining 4x4 rows & columns
char keys[ROWS][COLS] = {
  {'1','4','7','D'},
  {'2','5','8','E'},
  {'3','6','9','F'},
  {'A','B','C','G'}
};

//defining pins
byte rowPins[ROWS] = {10, 11, 12, 13}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A5, A4, A3, A2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int GetNumber()
{
   int num = 0;
   char key1 = keypad.getKey();
   switch (key1)
   {
     case NO_KEY:
      break;

    case '1': 
    num = 1;
    break;
    case '2': 
    num = 2;
    break;
    case 'A':
    num = 10;
    break;
    }
    
void setup(){
   Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  if (key){
    Serial.println(key);
  }
}
