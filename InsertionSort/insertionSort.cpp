#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int partition(int a[], int l, int h)
{

    int p, i, j, temp;
    p = a[l];
    i = l;
    j = h + 1;
    do
    {
        do
            i++;
        while (a[i] < p && i <= h);
        do
            j--;
        while (p < a[j]);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    swap(a[l],a[j]);
    return (j);
}
void quickSort(int arr[], int l, int h)
{
    int j = 0;
    if (l < h)
    {
        j = partition(arr, l, h);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, h);
    }
}
int main()
{
    int arr[] = {6, 8, 10, 1, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    quickSort(arr, 0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}