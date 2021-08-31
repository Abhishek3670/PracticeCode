#include <iostream>

using namespace std;
int solve(int x)
{
    int t = 1;
    for (int i = 1; i <= x; i++)
        t = t + i;
    return t;
}
int main()
{
    int n = 5;
    cout << 0.5*n*n+0.5*n+1<<endl;
    cout << solve(n);
}