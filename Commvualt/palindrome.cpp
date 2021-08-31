#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int maxPalindrome(char s[], int l, int r)
// {
//     int maxi = INT_MIN;
//     if (l > r)
//         return 0;
//     if (s[l] == s[r])
//         return 1 + maxPalindrome(s, l + 1, r - 1);
//     else
//         return maxi = max(maxPalindrome(s, l + 1, r), maxi);
// }

int maxPalindrome(char x[], char y[], int n, int m)
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
int main()
{
    char s[] = "atrpiiksskiipatcr";
    char r[] = "rctapiiksskiiprta";
    int n = 17;
    cout << maxPalindrome(s, r, n, n);
}