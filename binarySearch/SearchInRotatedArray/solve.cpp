#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int BS(vector<int> arr, int k, int l, int r)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int pivotIndex(vector<int> v)
{
    int l = 0;
    int n = v.size();
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        if (v[mid] < next && v[mid] < prev)
            return mid;
        else if (v[l] < v[mid])
            l = mid;
        else
            r = mid - 1;
    }
    return -1;
}
int search(vector<int> v, int t)
{
    int pivot = pivotIndex(v);
    if (pivot == 0)
        return BS(v, 0, v.size(), t);
    if (v[pivot] < t)
        return BS(v, t, 0, pivot - 1);
    else if (v[pivot] > t)
        return BS(v, t, pivot + 1, v.size());
    else if (v[pivot] == t)
        return pivot;
}

int main()
{
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    int target = 10;
    cout << search(v, target);
}