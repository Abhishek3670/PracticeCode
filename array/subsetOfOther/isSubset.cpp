#include <iostream>
#include <string.h>
#include <set>
#include <bits/stdc++.h>
using namespace std;
bool isSubset(int a1[], int a2[], int n, int m)
{

    set<int> hashset;

    for (int i = 0; i < n; i++)
    {
        hashset.insert(a1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (hashset.find(a2[i]) == hashset.end())
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {112, 53, 67, 51};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << isSubset(arr1, arr2, len1, len2);
    return 0;
}
