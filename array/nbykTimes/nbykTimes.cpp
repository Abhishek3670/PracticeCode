#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
void countOccurence(int arr[], int n, int k)
{
    int x = n/k;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]] ++;
    }
    for (int it = 0; it < m.size(); it++) {
        if (m[it] > x)
            cout << (it) << endl;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
     countOccurence(arr, len, k);
    return 0;
}
