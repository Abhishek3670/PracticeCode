#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// 3 sum zero

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> v;

    if (nums.size() < 3)
        return v;
    int l = 0, r = 0;
    sort(nums.begin(), nums.end());
    for (unsigned int i = 0; i < n; i++) // {-4,  -1,-1,0,1,2}
    {
        vector<int> t;
        int req = -nums[i]; // 1
        l = i + 1;          // 2
        r = n - 1;          // 5
        while (l < r)
        {
            long long sum = nums[l] + nums[r]; // 1
            if (sum < req)                     // 1 < 1
                l++;
            else if (sum > req) // 1 > 1
                r--;
            else if (sum == req) // 1 == 1
            {
                t.push_back(nums[i]);
                t.push_back(nums[l]);
                t.push_back(nums[r]);
                v.push_back(t);
                t.clear();
                while (l < r && nums[l] == t[1])
                    l++;
                while (l < r && nums[r] == t[2])
                    r--;
            }
            else
            {
                l++;
                r--;
            }
        }
        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }

    return v;
}

int main()
{
    vector<int> v = {-1, 0, -1, 1, 2, -4};
    vector<vector<int>> ans;
    ans = threeSum(v);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}