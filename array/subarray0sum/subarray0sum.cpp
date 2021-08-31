#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    set<int> sumSet;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;

        sumSet.insert(sum);
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int arr[] = {4, 2, -3, 1, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << subArrayExists(arr, len);
    return 0;
}
