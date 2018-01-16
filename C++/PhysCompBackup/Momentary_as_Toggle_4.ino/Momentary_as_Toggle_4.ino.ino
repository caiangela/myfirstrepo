#include <Keypad.h>

//defining 4x4 rows & columns
const byte ROWS = 4; 
const byte COLS = 4; 

//defining keypad pins
char keys[ROWS][COLS] = {
  {'1','5','9','D'},
  {'2','6','A','E'},
  {'3','7','B','F'},
  {'4','8','C','G'}
};
/*
1=3&2, 4=1&2, */

char key; 

byte rowPins[ROWS] = {10, 11, 12, 13}; //connect to the rows
byte colPins[COLS] = {A5, A4, A3, A2}; //connect to the columns

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v1;
#include "LedMatrixObject.h"

LedMatrixObject *led = new LedMatrixObject(2, 3, 4, 5, 6, 7, 8, 9);

unsigned char FistGap[16][16] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1},  
  {1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1},
  {1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//x
  {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//x
  {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},//x
  {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},//x
  {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void setup() {
  Serial.begin(9600);
}

void loop() {  
   v1 = GetNumber();
   v1.toInt();
   Serial.println(v1);

   if (num = 0){
   led->setScene(FistGap);
   led->draw();
    }
}

//function for v1, writes value into num
  String GetNumber()
{
   String num;
   char key = keypad.getKey();
   while(key != 'H')
   {
      switch (key)
      {
         case NO_KEY:
            break;

         case '1': case '2': case '3': 
         case '4': case '5': case '6': 
         case '7': case '8': case '9':
           Serial.println("key");
           Serial.println(key);
            num = key;
            Serial.println("num");
            Serial.println(num);
            break;

         case 'A':
         Serial.println("key");
           Serial.println(key);
         num = 10;
            Serial.println("num");
         Serial.println(num);
         break;
         
         case 'B':
         Serial.println("key");
           Serial.println(key);
         num = 11;
            Serial.println("num");
         Serial.println(num);
         break;
         
         case 'C':
         Serial.println("key");
           Serial.println(key);
         num = 12;
            Serial.println("num");
         Serial.println(num);
         break;   
               
         case 'D':
         Serial.println("key");
           Serial.println(key);
         num = 13;
            Serial.println("num");
         Serial.println(num);
         break;
                  
         case 'E':
         Serial.println("key");
           Serial.println(key);
         num = 14;
            Serial.println("num");
         Serial.println(num);
         break;
                  
         case 'F':
         Serial.println("key");
           Serial.println(key);
         num = 15;
            Serial.println("num");
         Serial.println(num);
         break;
                  
         case 'G':
         Serial.println("key");
           Serial.println(key);
         num = 16;
            Serial.println("num");
         Serial.println(num);
         break;
      }
      key = keypad.getKey();      
   }
   return num;
}
