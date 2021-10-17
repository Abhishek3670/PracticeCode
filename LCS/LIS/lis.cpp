#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int binarySearch(int arr[], int l, int h, int value)
{
    if (value > arr[h])
        return h + 1;
    while (h > l)
    {
        int middle = (h + l) / 2;
        if (arr[middle] == value)
            return middle;
        if (arr[middle] > value)
            h = middle;
        else
            l = middle + 1;
    }
    return h;
}

int longestSubsequence(int n, int a[])
{

    int tail[n];
    tail[0] = a[0];
    int lastIndex = 0;
    for (int i = 1; i < n; i++)
    {

        int index = binarySearch(tail, 0, lastIndex, a[i]);
        tail[index] = a[i];
        //  cout<<tail[i]<<endl;
        lastIndex = max(lastIndex, index);
    }

    return lastIndex + 1;
}

int LIS(int a[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = 1 + lis[j];
            }
        }
    }
    return *max_element(lis, lis + n);
}

int main()
{
    int arr[] = {0, 1, 0, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << LIS(arr, n) << endl;
    cout << longestSubsequence(n, arr);
}