// --->@important < ---
#include <iostream>
#include <map>
using namespace std;
int XORsubarray(int arr[], int n, int k)
{
    map<int, int> mp;
    int count = 0;
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = arr[i] ^ xorr;
        if (xorr == k)
            count++;
        if (mp.find(xorr ^ k) != mp.end())
            count += mp[xorr ^ k];
        mp[arr[i]]++;
    }
    return count;
}
int main()
{
    int arr[] = {4, 2, 2, 6, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << XORsubarray(arr, len, k);
}