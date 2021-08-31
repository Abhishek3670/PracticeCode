#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int LCS(char x[], char y[], int n, int m)
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
    char a[] = "abcdaf";
    char b[] = "acbcf";
    int n = 6;
    int m = 5;
    cout << m + n - LCS(a, b, n, m) << endl;
}