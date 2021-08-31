//Same of sum subset with difference
#include <iostream>
using namespace std;

int count(int arr[], int n, int k)
{
    int t[n + 1][k + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < k + 1; i++)
        t[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
        {
            if (arr[i - 1] <= k)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][k];
}

int main()
{
    int arr[] = {1, 1, 1, 1, 1};
    int n = 5;
    int target = 3;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int k = (sum - target) / 2;

    cout << count(arr, n, k);
}