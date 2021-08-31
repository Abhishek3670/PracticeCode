#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// To find maximum profit in stock
int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    int maxi = prices[0];
    int min = 99999;
    int max_profit = 0;
    for (int i = 0; i < size; i++)
    {
        if (prices[i] >= maxi)
        {
            maxi = prices[i];
        }
        if (prices[i] < min)
        {
            maxi = 0;
            min = prices[i];
        }

        max_profit = max((maxi - min), max_profit);
    }
    if (max_profit < 0)
        return 0;
    else
        return max_profit;
}
int maxProfitArray(int arr[], int n)
{
    int maxLower = 0;
    int maxi = arr[0];
    int profit = 0;
    int lower = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= maxi)
        {
            profit += arr[i] - maxi;
            maxi = arr[i];
        }
        else
        {
            lower = maxi - arr[i];
            if (maxLower < lower || maxi > arr[i])
            {
                maxLower += lower;
                maxi = arr[i];
            }
        }
    }
    return profit;
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(10);
    v.push_back(8);
    v.push_back(20);
    int arr[5] = {10, 20, 1, 5, 10};
    cout << maxProfit(v) << endl;
    cout << maxProfitArray(arr, 5);
}