#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int static t[1001][1002];

int LRS(char x[], char y[], int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (x[i - 1] == y[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n][m];
}
int main()
{
    char a[] = "AABEBCDD";

    int n = 8;

    cout << LRS(a, a, n, n) << endl;
}