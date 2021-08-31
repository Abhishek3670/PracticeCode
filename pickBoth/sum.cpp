#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    int left = 0;
    int n = A.size();
    int right = (n - B) + 1;
    int maxi = INT_MIN;
    for (int i = left; i < n; i++)
    {
        int sum = 0;
        int p = right;
        int j = B;
        do
        {
            sum += A[p];
            p++;
            p %= B + 1;
            j--;
        } while (j > 0);
        maxi = max(sum, maxi);
        right++;
        right %= B + 1;
    }
    return maxi;
}
int main()
{
    vector<int> v;
    v.push_back(-3);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(7);
    v.push_back(9);
    int k = 4;
    cout << solve(v, k);
}