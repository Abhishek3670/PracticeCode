#include <iostream>
#include <vector>
using namespace std;
int earlyFinish(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}
int maxMeetings(int start[], int end[], int n)
{
    vector<int> b;
    vector<vector<int> > v;
    for (int i = 0; i < n; i++)
    {

        b.push_back(start[i]);
        b.push_back(end[i]);
        v.push_back(b);
        b.clear();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << v[i][j] << ",";
        cout << " ";
    }

    int max = 1;
    int e = v[0][1];
    for (int j = 1; j < n; j++)
    {
        if (e <= v[j][0])
        {
            max++;
            e = v[j][1];
        }
    }
    return max;
}
int main()
{
    int start[] = {7,2,2,3};
    int end[] = {8,4,7,10};
    cout << " \n " << maxMeetings(start, end, 4);
    return 0;
}