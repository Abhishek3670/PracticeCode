#include <iostream>
using namespace std;
int start, len, end;

string reverse(string arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return arr;
}
void printArray(string arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    string arr = "Hello";
    int len = arr.length();
    cout << "Before reversing" << endl;
    printArray(arr, len);
    cout << endl
         << "after reversing" << endl;
    string newArr = reverse(arr, 0, len - 1);
    printArray(newArr, len);
}
