#include <iostream>
#include <vector>

using namespace std;

int findMinPath(vector<vector<int>> &V, int r, int c)
{
    int R = V.size();
    int C = V[0].size();
    if (r >= R || c >= C)
        return 100000000; // Infinity
    if (r == R - 1 && c == C - 1)
        return 0;
    return V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
}
int memo[101][101];
int findMinPath(vector<vector<int>> &V, int r, int c)
{
    int R = V.size();
    int C = V[0].size();
    if (r >= R || c >= C)
        return 100000000; // Infinity
    if (r == R - 1 && c == C - 1)
        return 0;
    if (memo[r][c] != -1)
        return memo[r][c];
    memo[r][c] = V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
    return memo[r][c];
}
int main()
{
    vector<vector<int>> v;
    v.push_back({})
        v.push_back({})
            v.push_back({})
                v.push_back({})
}