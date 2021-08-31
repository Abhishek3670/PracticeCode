#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

string printLCS(char x[], char y[], int n, int m)
{

    int t[n + 1][m + 1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (x[i - 1] == y[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);

    int i = n;
    int j = m;
    string ss = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ss = ss + x[i - 1];
            i--;
            j--;
        }
        else if (t[i - 1][j] <= t[i][j - 1])
        {
            ss = ss + y[j - 1];
            j--;
        }

        else if (t[i - 1][j] > t[i][j - 1])
        {
            ss = ss + x[i - 1];
            i--;
        }
    }
    while (i > 0)
    {
        ss += x[i - 1];
        i--;
    }
    while (j > 0)
    {
        ss += y[j - 1];
        j--;
    }
    reverse(ss.begin(), ss.end());
    return ss;
}
int main()
{
    char a[] = "abcdaf";
    char b[] = "acbcf";
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << printLCS(a, b, n, m);
}