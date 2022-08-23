
#include <iostream>
#include "fsint.h"
using namespace std;

int main(void)
{
    long int numLong = 10;
    int num = 9;
    fsint temp1 = -4, temp2 = -2;
    /*//cin >> temp1;
    temp1 += -1;
    
    cout << temp1 << endl;
    temp1 += temp2;
    cout << temp1 << endl;
    temp1 = -100;
    temp1 = temp1 + numLong;
    
    cout << temp1 << endl << sizeof(fsint) << endl;*/
    if (temp1 > temp2)
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }

    system("pause");
    return 0;
}
