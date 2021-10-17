#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
vector<int> solveOn(vector<int> v)
{
    stack<int> st;
    int n = v.size();
    vector<int> t(n, -1);
    for (int i = (2 * n - 1); i >= 0; i--)
    {
        while (!st.empty() && st.top() <= v[i % n])
            st.pop();
        if (i < n)
            if (!st.empty())
                t[i] = st.top();
        st.push(v[i % n]);
        // for(auto i : t)
        //     cout<<i <<" ";
        // cout << endl;
    }
    return t;
}

vector<int> solve(vector<int> v)
{
    vector<int> t;
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        int j = i + 1;
        while (j != i)
        {
            if (v[i] < v[j])
            {
                t.push_back(v[j]);
                break;
            }
            j = ++j % n;
        }
        if (j == i)
            t.push_back(-1);
    }
    return t;
}
int main()
{
    vector<int> v{3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    int n = v.size();
    vector<int> ans = solve(v);
    // vector<int> ans = solveOn(v);
    for (auto i : ans)
        cout << i << " ";
}