#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

string printLCS(char x[], char y[], int n, int m)
{
    map<char, int> mpp;
    int t[n + 1][m + 1];
    memset(t, 0, sizeof(t));
    char lcs[] = {0, 0, 0, 0, 0};
    int g = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][m - 1];
                //mpp[x[i-1]]++;
            }
            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }
    //    for(auto i : mpp)
    //     cout << i.first;
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
        else if (t[i - 1][j] < t[i][j - 1])
            j--;
        else
            i--;
    }
    reverse(ss.begin(), ss.end());
    return ss;
}
// void reverse(char b[], int n)
// {
//     for (int i = 0; i < n/2; i++)
//     {
//         swap(b, b + n);
//     }
// }
int main()
{
    char a[] = "agbcba";
    char b[] = "abcbga";
    int n = 6;
    // char b[5];
    // copy(begin(a), end(a), end(b));
    // reverse(b, n);

    cout << printLCS(a, b, n, n);
}