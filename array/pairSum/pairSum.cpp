#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;
int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> m;

    // Store counts of all elements in map m
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int twice_count = 0;

    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < n; i++)
    {
        twice_count += m[k - arr[i]];

        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (k - arr[i] == arr[i])
            twice_count--;
    }

    // return the half of twice_count
    return twice_count / 2;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int count = getPairsCount(arr, n, k);

    cout << count << endl;

    return 0;
}
