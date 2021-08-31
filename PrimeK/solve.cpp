#include <iostream>
#include <set>
using namespace std;

int solve(set<int> s, int k)
{
    int c = 0;
    for (auto &i : s)
        if (s.find(i + k) != s.end())
            c++;
    return c;
}
int main()
{
    int n = 5;
    int m = 30;
    int count = 0;
    set<int> s;
    for (int i = n; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                count++;
        }
        if (count == 2)
            s.insert(i);
        count = 0;
    }
    cout << solve(s, 6);
}