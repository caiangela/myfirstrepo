#include <iostream>
using namespace std;

int main()
{
    int x = 4;
    int y = x++;
    // x=5, y=4.
    
    if (x != y) {
        cout <<  "Yeh";
    }

    return 0;
}

