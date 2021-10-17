#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<vector<int>> lookup;

int solve(int S[], int n, int S1, int S2)
{
    if (n < 0)
        return abs(S1 - S2);
    int &ans = lookup[n][S1];
    if (ans != -1)
        return ans;
    int inc = solve(S, n - 1, S1 + S[n], S2);
    int exc = solve(S, n - 1, S1, S2 + S[n]);

    ans = min(inc, exc);
    return ans;
}
int minDifference(int arr[], int n)
{
    lookup.clear();
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];

    lookup.resize(n);
    for (int i = 0; i < n; ++i)
        lookup[i].assign(sum + 1, -1);
    return solve(arr, n - 1, 0, 0);
}

vector<int> sumSubset(int arr[], int n, int k)
{
    vector<int> v;
    bool t[n + 1][k + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = true;
    for (int i = 1; i < k + 1; i++)
        t[0][i] = false;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < k + 1; j++)
        {
            if (arr[i - 1] <= k)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
    for (int i = 1; i < (k + 1) / 2; i++)
        if (t[n][i] == 1)
            v.push_back(i);
    return v;
}
int miniSubset(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<int> v;
    v = sumSubset(arr, n, sum);
    int mini = INT_MAX;
    for (int i = 0; i < v.size(); i++)
        mini = min(sum - v[i] * 2, mini);
    return mini;
}
int main()
{
    int arr[] = {1, 6, 11, 5};
    int n = 4;
    cout << miniSubset(arr, n) << endl;
    cout << minDifference(arr, n);
}