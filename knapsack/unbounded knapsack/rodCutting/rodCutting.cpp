#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int w[], int v[], int W, int n)
{
    int t[n + 1][W + 1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < W + 1; j++)
            if (w[i - 1] <= j)
                t[i][j] = max(t[i][j - w[i - 1]] + v[i - 1], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
    return t[n][W];
}
// line segment 
 int maximizeTheCuts(int n, int x, int y, int z)
    {
       int arr[] = {x,y,z};
       sort(arr,arr + 3);
       int t[n+1];
       memset(t,0,sizeof(t));
       for(int j=0;j<3;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(i==arr[j] or (i>arr[j] and t[i-arr[j]]>0))
                    t[i]=max(t[i-arr[j]]+1,t[i]);
                }
        }
       
        return t[n];
    }
int main()
{
    int length[] = {1, 2, 3, 4, 5, 6, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = 10;
    int n = 8;    
    cout << maxProfit(length, price, N, n)<<endl; 
    cout << maximizeTheCuts(5, 5, 3, 2);
}