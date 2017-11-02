#include <iostream>
using namespace std;

int main()
{
    int b = 0;
    int x[3][4] = {{1,3,5,7}, {2,4,6,8}, {9,11,13,15}};
    
    cin >> b;
    
    cout << x[2][3] + b << endl;

    /*row[2] column[3] is 4th number on 3rd row
     *which is 15
     *if I input 15 into b
     output would be 25
     */
    
    return 0;
}

