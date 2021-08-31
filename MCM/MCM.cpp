#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int MCM(int arr[], int i, int j)
{
    int ans = INT_MAX;
    if (i >= j)
        return 0;
    for (int k = i; k < j; k++)
    {
        int temp_ans = MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(temp_ans, ans);
    }
    return ans;
}
int MCMmemozise(int arr[], int i, int j)
{

    if (i > j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];
    for (int k = 1; k < j; k++)
    {
        int temp = MCMmemozise(arr, i, k) + MCMmemozise(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        t[i][j] = min(temp, t[i][j]);
    }
    return t[i][j];
}
int main()
{
    int arr[] = {10, 20, 30, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(t, -1, sizeof(t));
    cout << MCM(arr, 1, n - 1);
    cout << MCMmemozise(arr, 1, n - 1);
}