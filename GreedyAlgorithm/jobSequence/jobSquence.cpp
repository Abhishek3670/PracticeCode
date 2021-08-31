#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
void print(Job arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << "\n";
    }
}
bool comparisons(Job &a, Job &b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> v;
    sort(arr, arr + n, comparisons);
    print(arr, n);
    int isFree[n];
    int j = 0;
    char slot[n];
    for (int i = 0; i < n; i++)
        isFree[i] = true;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i].dead - 1;
        if (isFree[temp] == true)
        {
            slot[temp] = arr[i].id;
            isFree[temp] = false;
            j++;
        }
        else if (isFree[temp - 1] == true)
        {
            slot[temp - 1] = arr[i].id;
            isFree[temp - 1] = false;
            j++;
        }
    }
    for (int i = 0; i < j; i++)
        v.push_back(slot[i]);
    return v;
}

int main()
{
    Job obj[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(obj) / sizeof(obj[0]);
    vector<int> v;

    cout << "max profit : \n";
    v = JobScheduling(obj, n);
    for (auto i = v.begin(); i < v.end(); i++)
        cout << *i << ",";
    return 0;
}