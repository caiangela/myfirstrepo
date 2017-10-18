#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    
    do {
        cout << a << endl;
        a-=2;
    } while (a >= 6);
    
/* run programme once first before testing
   so '10' would be printed first no matter a>=6 or not ?
*/

    return 0;
}
