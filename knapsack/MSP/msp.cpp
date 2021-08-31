#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int MSP(int arr[], int cal, int i, int sum)
{
    if (i == 0)
        return abs((sum - cal) - cal);
    return min(MSP(arr, cal + arr[i-1], i - 1, sum),
               MSP(arr, cal, i - 1, sum));
}
int main()
{
    int arr[] = {1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    cout << MSP(arr, 0, n, sum);
}