#include <iostream>

using namespace std;

bool sumSubset(int arr[], int n, int k)
{
    bool t[n + 1][k + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = true;
    for (int i = 1; i < k + 1; i++)
        t[0][i] = false;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
        {
            if (arr[i - 1] <= k)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
    return t[n][k];
}
int main()
{
    int arr[] = {1, 2, 7};
    int n = 3;
    int sum = 10;
    cout << sumSubset(arr, n, sum);
}