#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int static t[100][100];

int maxProfit(int w[], int v[], int W, int n)
{
    if (w == 0 || n == 0)
        return 0;
    if (w[n - 1] <= W)
        return max(v[n - 1] + maxProfit(w, v, W - w[n - 1], n - 1), maxProfit(w, v, W, n - 1));
    else
        return maxProfit(w, v, W, n - 1);
}
int maxProfitMemoize(int w[], int v[], int W, int n)
{
    if (w == 0 || n == 0)
        return 0;
    if (t[n][W] != -1)
        return t[n][W];
    if (w[n - 1] <= W)
        return t[n][W] = max(v[n - 1] + maxProfit(w, v, W - w[n - 1], n - 1), maxProfit(w, v, W, n - 1));
    else
        return t[n][W] = maxProfit(w, v, W, n - 1);
}
int maxProfitTopDown(int w[], int v[], int W, int n)
{
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < W + 1; j++)
        {
            if (w[i - 1] <= j)
                t[i][j] = max(v[i - 1] + t[i - 1][j - w[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][W];
}
int main()
{
    int w[] = {1, 3, 4, 5};
    int v[] = {1, 4, 5, 7};
    int W = 7;
    int n = 4;
    memset(t, -1, sizeof(t));
    cout << "Recursion method : " << maxProfit(w, v, W, n) << endl;
    cout << "Memoize method: " << maxProfitMemoize(w, v, W, n) << endl;
    cout << "Top Down method: " << maxProfitTopDown(w, v, W, n) << endl;
}