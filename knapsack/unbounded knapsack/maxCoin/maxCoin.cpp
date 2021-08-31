#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int maxiCoin(int arr[], int n, int k)
{
    int t[n + 1][k + 1];
    memset(t, 0, sizeof(t));
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < k + 1; i++)
        t[0][i] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
            if (arr[i - 1] <= j)
                t[i][j] = t[i][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
    return t[n][k];
}
int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    int sum = 4;
    cout << maxiCoin(arr, n, sum);
}