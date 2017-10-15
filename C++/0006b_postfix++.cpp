#include <iostream>
using namespace std;

int main()
{
    int x = 11;
    int y = x++;

    //Note: postfix means first y=x, then x=x+1; 
    //x=12, y=11;

    cout << x << endl << y << endl;
    
    return 0;
}

