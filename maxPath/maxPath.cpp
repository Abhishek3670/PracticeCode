#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int dp[N][N];
        for (int i = 0; i < N; i++)
            dp[0][i] = Matrix[0][i];

    
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j == 0 && j + 1 < N)
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);
                else if (j - 1 >= 0 && j == N - 1)
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
                else if (j > 0 && j + 1 < N)
                    dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1]));
                else
                    dp[i][j] = Matrix[i][j] + dp[i - 1][j];
            }
        }

            int maxi = 0;
        for (int i = 0; i < N; i++)
            maxi = max(maxi, dp[N - 1][i]);

        return maxi;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
}
