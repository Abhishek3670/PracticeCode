#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int arr[], int n)
{
    int profit = 0 ;
    int currUp[n] ; 
    currUp[0] = 0;
    int currDown[n];
    for (int i = 1 ; i< n;i++){
        int sub = arr[i] - arr[i-1];
        if(sub > 0)
        {
            
             currUp[i] = sub;
        }
        else {

             currUp[i] = sub;
        }
    }
    cout<<currUp[0]<<endl;
    cout<<currUp[1]<<endl;
    cout<<currUp[2]<<endl;
    cout<<currUp[3]<<endl;
    cout<<currUp[4]<<endl;
    cout<<currUp[5]<<endl;
    return 0;
}
int main(int argc, char const *argv[])
{
    int arr[] = {10, 22, 5, 75, 65, 80};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit(arr, len);
    return 0;
}
