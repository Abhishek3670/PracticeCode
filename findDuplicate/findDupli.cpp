#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector < int > nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
int main()
{
    vector<int> n ;
    n.push_back(1);
    n.push_back(9);
    n.push_back(1);
    n.push_back(5);
    n.push_back(2);
    cout<<findDuplicate(n);
}