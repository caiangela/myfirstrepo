#include <iostream>
using namespace std;

int main()
{
    for(int a = 50; a > 10; a -= 10){
        cout << a << endl;
        // outputs 50, 40, 30, 20.
    }

    return 0;
}
