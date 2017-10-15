#include <iostream>
using namespace std;

int main()
{
    int x = 11;
    int y = ++x;

    //Note: prefix means first x=x+1, then y=x+1. 
    //x=12, y=12.

    cout << x << endl << y << endl;
    
    return 0;
}

