#include <iostream>
using namespace std;

int main()
{
    int age = 52;
    switch (age) {
        case 18:
        cout << "adult";
        break;
        case 52:
        cout << "middle age";
        break;
        //if we don't break here the programme will keep executing
        case 90:
        cout << "history"; //excuse my sloppy naming
        break;
        default:
        cout << "sorry what is this";
    }

    return 0;
}