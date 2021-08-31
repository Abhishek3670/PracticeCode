#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minInsertionLPS(char arr[], int n)
{
    int t[n + 1][n + 1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < n + 1; j++)
            if (arr[i - 1] == arr[n - j])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
    return n - t[n][n];
}
int main()
{
    char a[] = "aebcbda";
    int n = 7;

    cout << minInsertionLPS(a, n);
}