#include <iostream>
using namespace std;

// This one exercise is directly from Sololearn
// didn't customize it much, just used the provided conditions 
// but tried to do it from my own head

// among age > 14
// if >= 18, output adult; if <18, output teenager
// among others
// output child, or output error

int main(){

   int age = 18;
   
   if (age > 14){
       if (age >= 18){
           cout << "adult";
   }
       else{
           cout << "teen";
           }
       
   }
   
   else{
       if (age > 0){
           cout << "child";
   }
       
       else {
           cout << "error" << endl;
       }
   }
}

