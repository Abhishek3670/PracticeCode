// --> Important <--

#include <iostream>
#include <unordered_map>

using namespace std;

int findSubArraySum(int Arr[], int N, int k)
{
    unordered_map<int, int> prevk;
    int res = 0;
    int currk = 0;
    for (int i = 0; i < N; i++)
    {
        currk += Arr[i];
        if (currk == k)
            res++;
        else
        {
            if (prevk.find(currk - k) != prevk.end())
                res += prevk[currk-k];
            prevk[currk]++;  
        }
    }
    return res;
}
int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    int k = -10;
    cout << findSubArraySum(arr, len, k);
}