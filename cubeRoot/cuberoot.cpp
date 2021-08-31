#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double diff(double n, double mid)
{
    if ((mid * mid * mid) > n)
        return ((mid * mid * mid) - n);
    else
        (n - (mid * mid * mid));
}
double cubeRoot(double n)
{
    double left = 0;
    double right = n;
    double e = 0.00000001;
    while (true)
    {
        double mid = (left + right) / 2;
        double error = diff(n, mid);
        if (error <= e)
            return mid;
        if ((mid * mid * mid) > n)
            right = mid;
        else
            left = mid;
    }
}
int main()
{
    double n = -8;
    if (n < 0)
        cout << cubeRoot(-n)<<"i";
    else
        cout << cubeRoot(n);
}