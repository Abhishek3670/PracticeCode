#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    set<int> con;
    int maxi = 0;
    if (nums.size() == 0)
        return maxi;
    for (auto num : nums)
        con.insert(num);

    for (auto num : nums)
        if (!con.count(num - 1))
        {
            int cur = num;
            int count = 1;
            while (con.count(cur + 1))
            {
                cur += 1;
                count += 1;
            }
            maxi = max(maxi, count);
        }
    return maxi;
}
int longestCon(int arr[], int n)
{
    int ans = 0, count = 0;

    // sort the array
    sort(arr, arr + n);

    vector<int> v;
    v.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }

    for (int i = 0; i < v.size(); i++)
    {

        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;

        else
            count = 1;

        ans = max(ans, count);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int arr[] = {2, 6, 1, 4, 3, 8, 4, 9, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<int> v{2, 6, 1, 4, 3, 8, 4, 9, 4};
    cout << longestConsecutive(v);
    return 0;
}
