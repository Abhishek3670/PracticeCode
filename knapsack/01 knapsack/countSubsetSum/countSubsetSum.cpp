#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int k)
{
    int t[n + 1][k + 1];

    t[0][0] = 1;
    for (int i = 1; i < k + 1; i++)
        t[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        t[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            else
                t[i][j] = t[i - 1][j];

    // for (int i = 1; i < n + 1; i++)
    // {
    //     for (int j = 1; j < k + 1; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
    return t[n][k];
}
int main()
{
    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = 6;
    int sum = 10;
    cout << count(arr, n, sum);
}