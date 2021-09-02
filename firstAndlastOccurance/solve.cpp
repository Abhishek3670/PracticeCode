#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> v, int l, int r, int k)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v[mid] == k)
            return mid;
        else if (v[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int lastOccurance(vector<int> v, int k)
{
    int last;
    int index = binarySearch(v, 0, v.size() - 1, k);
    while (index != -1)
    {
        last = index;
        index = binarySearch(v, index + 1, v.size() - 1, k);
    }
    return last;
}
int firstOccurance(vector<int> v, int k)
{
    int first;
    int index = binarySearch(v, 0, v.size() - 1, k);
    while (index != -1)
    {
        first = index;
        index = binarySearch(v, 0, index - 1, k);
    }
    return first;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int first = firstOccurance(nums, target);
    int last = lastOccurance(nums, target);
    return first <= last ? vector<int>{first, last} : vector<int>(2, -1);
}
int main()
{
    vector<int> v{5, 8, 8, 8, 8, 10};
    vector<int> ans = searchRange(v, 8);
    for (auto i : ans)
        cout << i << " " << endl;
}