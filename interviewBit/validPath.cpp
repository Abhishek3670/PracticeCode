#include <iostream>

using namespace std;
#define N 2
int solve(int arr[][N], int i, int j)
{
    // cout << arr[i][j] << " ";
    if (i == N - 1 && j == N - 1)
        return 1;
    if (arr[i][j] > arr[i][j + 1] && j + 1 < N)
        return solve(arr, i, j + 1);
    if (arr[i][j] > arr[i + 1][j])
        return solve(arr, i + 1, j);
    if (arr[i][j] > arr[i][j - 1])
        return solve(arr, i, j - 1);
    return 0;
}
int main()
{
    int arr[][2] = {
        {90, 96},
        {61, 89},

    };
    // int arr[][5] = {
    //     {100, 95, 90, 85, 80},
    //     {100, 100, 100, 100, 75},
    //     {50, 55, 60, 65, 70},
    //     {45, 100, 100, 100, 100},
    //     {40, 35, 30, 25, 20}};
    int i = 0;
    int j = 0;
    cout << solve(arr, i, j);
}