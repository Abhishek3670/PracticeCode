#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
// merge 2 sorted array without changing its individual size
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void merge(int arr1[], int arr2[], int len1, int len2)
{
    int temp = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr2[j], arr1[i]);
            }
        }
    }
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr2[i] < arr2[j])
                swap(arr2[i], arr2[j]);
        }
    }
    sort(arr2, arr2 + len2);
}
int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "arr1 :" << endl;
    printArray(arr1, len1);
    cout << endl;
    cout << "arr2 :" << endl;
    printArray(arr2, len2);

    merge(arr1, arr2, len1, len2);
    cout << endl;
    cout << "arr1 :" << endl;
    printArray(arr1, len1);
    cout << endl;
    cout << "arr2 :" << endl;
    printArray(arr2, len2);
}