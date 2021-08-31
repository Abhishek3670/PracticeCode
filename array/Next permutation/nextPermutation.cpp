#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void reverse(vector<int> arr, int i, int n)
{
    while (i > n)
        swap(arr[i], arr[n]);
}
vector<int> nextPermutation(int N, vector<int> arr)
{
    int ind = 0;
    vector<int> v = arr;
    for (int i = N - 2; i >= 0; i--)
    {
        if (v[i] < v[i + 1])
        {
            ind = i;
            break;
        }
    }
    for (int i = N - 1; i > ind; i--)
    {
        if (v[i] > v[ind])
        {
            swap(v[i], v[ind]);
            ind++;
            break;
        }
    }
    for (int i = 0; i < (N - ind) / 2; i++)
        swap(v[i + ind], v[N - i - 1]);
    return v;
}
int main()
{
    vector<int> v, arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(2);
    int n = arr.size();
    display(arr);
    v = nextPermutation(n, arr);
    display(v);
    return 0;
}