#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int static t[1001][1002];
int LCS(char x[], char y[], int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
        return 1 + LCS(x, y, n - 1, m - 1);
    else
        return max(LCS(x, y, n - 1, m), LCS(x, y, n, m - 1));
}
int LCS_memozise(char x[], char y[], int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (t[n][m] != -1)
        return t[n][m];
    if (x[n - 1] == y[m - 1])
        return t[n][m] = 1 + LCS_memozise(x, y, n - 1, m - 1);
    else
        return t[n][m] = max(LCS_memozise(x, y, n - 1, m), LCS_memozise(x, y, n, m - 1));
}
int LCS_topbuttom(char x[], char y[], int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n][m];
}
int main()
{
    char a[] = "AGGTAB";
    char b[] = "GXTXAYB";
    int n = 6;
    int m = 7;
    memset(t, -1, sizeof(t));
    cout << LCS(a, b, n, m) << endl;
    cout << LCS_memozise(a, b, n, m) << endl;
    cout << LCS_topbuttom(a, b, n, m) << endl;
}