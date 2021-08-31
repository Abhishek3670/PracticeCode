#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > mergei(vector<vector<int> > &intervals)
{
    vector<vector<int> > mergedIntervals;
    if (intervals.size() == 0)
    {
        return mergedIntervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    vector<int>::iterator it;

    for (it : intervals)
    {
        if (it[0] <= tempInterval[1])
        {
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else
        {
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}

int main()
{
    vector<vector<int> > v;
    vector<int>::iterator it;
    for (it = v.begin() , it != v.end(); ++it)
    {
        cin >> it[0];
        cin >> it[1];
    }
    vector<vector<int> > ans = mergei(v);

     for (it = v.begin() , it != v.end(); ++it)
    {
        cout << it[0];
        cout << it[1];
    }
}
