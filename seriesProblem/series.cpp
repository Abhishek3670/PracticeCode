#include <iostream>
#include <math.h>
using namespace std;

long double NthTerm(int N)
{
    long double res;
    if (!(N % 2))
        res = (long double)pow(2, (long long int)pow(3, N / 2 - 1));
    else
        res = (long double)pow(2, (long long int)pow(2, N / 2));
    return res;
}

int main()
{
    int N = 30;
    cout << NthTerm(N);
}