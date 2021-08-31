#include <iostream>
using namespace std;

bool equalSumPartiton(int arr[], int n,int sum)
{
    
    bool t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= sum)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    return t[n][sum];
}
int main()
{
    int arr[] = {6, 2, 3, 1, 8};
    int n = 5;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    if(sum % 2 == 0)
         cout << equalSumPartiton(arr, n,sum/2);
    else
        cout<<"not possible";
}