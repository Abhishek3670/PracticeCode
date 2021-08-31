#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int minimizedTower(int house[], int n, int range)
{
    sort(house, house + n);
    int numOfTower = 0;
    int i = 0;
    while (i < n)
    {
        numOfTower++;
        int loc = house[i] + range;
        while (i < n && house[i] <= loc)
            i++;
        --i;
        loc = house[i] + range;
        while (i < n && house[i] <= loc)
            i++;
    }

    return numOfTower;
}
int main()
{
    int arr[] = {1, 2, 3, 5, 10};
    int k = 2;
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << minimizedTower(arr, len, k);
}