#include <iostream>
#include <math.h>
using namespace std;
// maximum sum of an subarray
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int maxSubarraySum(int arr[], int n)
{
    int max_so_far = 0, max_current = 0;
    for (int i = 0; i < n; i++)
    {
        max_current += arr[i];
        max_so_far = max(max_current, max_so_far);
        if (max_current < 0)
            max_current = 0;
    }
    return max_so_far;
}
int main()
{
    int arr[] = {2, 1, -1, 2, -3};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    cout << endl;
    int maxSum = maxSubarraySum(arr, len);
    cout << endl;
    cout << maxSum << endl;
}