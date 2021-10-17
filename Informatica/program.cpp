#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int n, int k)
{
    vector<vector<int>> v;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (i % k == 0 && i != 0)
        {
            v.push_back(temp);
            temp.clear();
        }
        temp.push_back(arr[i]);
    }
    v.push_back(temp);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[0].size(); j++)
            cout << v[i][j] << " ";
}

int main(int argc, const char **argv)
{
    vector<int> arr = {1, 32, 5, 6, 9, 3};
    int n = arr.size();
    int k = 2;
    solve(arr, n, k);
    return 0;
}