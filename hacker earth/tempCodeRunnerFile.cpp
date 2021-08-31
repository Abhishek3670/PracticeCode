#include <bits/stdc++.h>
using namespace std;
bool solve(int a[], int n, int psum[], int m, int x)
{
    int *low = lower_bound(a, a + n, x);
    low--;
    int l1 = low - a;
    int *upr = upper_bound(a, a + n, x);
    int u1 = upr - a;
    if ((a[l1] < x && x < a[u1]) && (psum[l1] == psum[m - 1] - psum[u1 - 1]))
    {
        return true;
    }
    return false;
}
bool coins_chq(int a[], int n)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        max_ele = max(a[i], a[i + 1]);
    }
    int psum[n];
    psum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        psum[i] = psum[i - 1] + a[i];
    }
    for (int i = 1; i <= max_ele; i++)
    {
        if (solve(a, n, psum, n, i))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (coins_chq(a, n))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}