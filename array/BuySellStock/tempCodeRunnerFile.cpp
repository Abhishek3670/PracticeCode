#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    int max = prices[0];
    int min = 99999;
    int max_profit = 0;
    for (int i = 0; i < size; i++)
    {
        if (prices[i] >= max)
        {
            max = prices[i];
        }
        if (prices[i] < min && i != size-1)
        {
            max = 0;
            min = prices[i];
        }
        if (max - min > max_profit)
            max_profit = max - min;
    }
    if(max_profit < 0)
    return 0;
    else
    return max_profit;
}
int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(6);
    v.push_back(5);
    v.push_back(0);
    v.push_back(3);

    int max = maxProfit(v);
    cout << max;
}