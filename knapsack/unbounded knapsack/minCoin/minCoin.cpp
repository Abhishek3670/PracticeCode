#include <iostream>

using namespace std;

int minCoin(int arr[], int n, int k)
{
    int t[n + 1][k + 1];
    for (int i = 1; i < n + 1; i++)
        t[i][0] = 0;

    for (int i = 0; i < k + 1; i++)
        t[0][i] = INT_MAX - 1;
    for (int i = 1; i < k + 1; i++)
        if (i % arr[0] == 0)
            t[1][i] = i / arr[0];
        else
            t[1][i] = INT_MAX - 1;

    for (int i = 2; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
            if (arr[i - 1] <= j)
                t[i][j] = min(t[i][j - arr[i - 1]] + 1, t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < k + 1; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
    return t[n][k];
}
int main()
{
    int arr[] = {9, 6, 5, 1};
    int n = 3;
    int sum = 11;
    cout << minCoin(arr, n, sum);
}