#include <iostream>

using namespace std;

int binarysearch(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;
    int mid = (l + r) / 2;
    while (l != r)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            l = mid;
            mid = (l + r) / 2;
        }
        else
        {
            r = mid;
            mid = (l + r) / 2;
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << " found at : " << binarysearch(arr, n, k) + 1;
    return 0;
}