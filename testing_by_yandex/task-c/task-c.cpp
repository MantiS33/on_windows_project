#include <iostream>
using namespace std;

int greatestComminDivisor(unsigned int a, unsigned int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

bool isPrimeNumber(unsigned int n)
{
    bool isPrimeNumber = true;

    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            isPrimeNumber = false;
            break;
        }
    }
    return isPrimeNumber;
}

int main(void)
{
    int t;
    cin >> t;
    unsigned int** arrAB = new unsigned int* [t];
    for (int i = 0; i < t; ++i)
    {
        arrAB[i] = new unsigned int[2];
        cin >> arrAB[i][0] >> arrAB[i][1];
    }

    for (int i = 0; i < t; ++i)
    {
        unsigned int greatest = 2;
        for (int j = 3; j <= max(arrAB[i][0], arrAB[i][1]); j += 2)
        {
            if (isPrimeNumber(j))
            {
                if (greatest < max(greatestComminDivisor(arrAB[i][0] * j, arrAB[i][1]), greatestComminDivisor(arrAB[i][0], arrAB[i][1] * j)))
                {
                    greatest = max(greatestComminDivisor(arrAB[i][0] * j, arrAB[i][1]), greatestComminDivisor(arrAB[i][0], arrAB[i][1] * j));
                }
            }

        }
        cout << greatest << endl;
        greatest = 0;
    }
    return 0;
}