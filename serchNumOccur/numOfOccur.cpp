#include <iostream>
#include <vector>
using namespace std;
int searchNumOccurrence(vector<int> &V, int k, int start, int end)
{
    if (start > end)
        return 0;
    int mid = (start + end) / 2;
    if (V[mid] < k)
        return searchNumOccurrence(V, k, mid + 1, end);
    if (V[mid] > k)
        return searchNumOccurrence(V, k, start, mid - 1);
    return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);
}
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    int k = 3;
    cout << searchNumOccurrence(v, 3, 0, 5);
}