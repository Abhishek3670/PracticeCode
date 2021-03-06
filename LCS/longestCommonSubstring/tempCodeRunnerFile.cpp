
int LCS(char x[], char y[], int n, int m)
{
    int dp[n + 1][m + 1];
    int maxi = INT_MIN;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxi = max(dp[i][j], maxi);
            }
            else
                dp[i][j] = 0;

    return maxi;
}