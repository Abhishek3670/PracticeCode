#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

bool SPM(char x[], char y[], int n, int m)
{
    int t[n + 1][m + 1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    if (t[n][m] == min(n, m))
        return true;
    else
        return false;
}
int main()
{
    char a[] = "AXY";
    char b[] = "ADXCPY";
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << SPM(a, b, n, m);
}