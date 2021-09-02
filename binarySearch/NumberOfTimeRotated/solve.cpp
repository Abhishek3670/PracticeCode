#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// O(logn) - No. of times an array is rotated
int solve(vector<int> v)
{
    int l = 0;
    int r = v.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int prev = (mid + v.size() - 1) % v.size();
        int next = (mid + 1) % v.size();
        if (v[mid] < v[prev] && v[mid] < v[next])
            return mid;
        else if (v[l] > v[mid])
            r = mid - 1;
        else
            l = mid;
    }
    return -1;
}
int main()
{
    vector<int> v{4, 5, 6, 0, 1, 2};
    cout << "No. of times Rotated : " << solve(v);
}