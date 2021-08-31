#include <iostream>
using namespace std;
// rotating array by one element forward
void printArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}
void cyclicRotation(int arr[], int len)
{
    int last_elem = arr[len - 1];
    for (int i = len - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last_elem;
}
int main()
{
    int arr[] = {9, 8, 7, 6, 4, 2, 1, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, len);
    cout << endl;
    cyclicRotation(arr, len);
    cout << endl;
    printArray(arr, len);
}