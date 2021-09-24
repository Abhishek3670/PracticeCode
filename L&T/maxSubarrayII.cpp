#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxSubarray(vector<int> &v)
{
    if (v.size() == 0)
        return -2;
    set<int> s;
    int ans = INT_MIN, sum = 0;
    for (auto i : v)
    {
        if (s.count(i))
        {
            ans = max(ans, sum);
            sum = 0;
        }
        else
        {
            sum += i;
            s.insert(i);
        }
    }
    if (ans == INT_MIN)
        return -1;
    return ans;
}
int main()
{
    vector<int> v{2, 3, 5, 6, 10, 7, 8, 9};
    cout << maxSubarray(v);
}