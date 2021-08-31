#include <iostream>
using namespace std;
long long maxProSubArr(int arr[] , int n){
    int mini[n];       // minimum product ending with ith index
    int maxi[n];       // maximum product ending with ith index
    
    mini[0]=arr[0];
    maxi[0]=arr[0];
    
    int ans = arr[0];
    for(int i=1;i<n;i++) 
    {
        if(arr[i]>0)
        {
            maxi[i] = max(maxi[i-1]*arr[i], arr[i]);
            
            mini[i] = min(mini[i-1]*arr[i], arr[i]);
            
        }
        else
        {
            maxi[i] = max(mini[i-1]*arr[i], arr[i]);
           
            mini[i] = min(maxi[i-1]*arr[i], arr[i]);
            
        }
        ans = max(ans, maxi[i]);
    }
    return ans;
}
int main()
{
  
    int arr[] = {-2, 3, 4, -1, 0};
    int len = sizeof(arr)/sizeof(arr[0]);
    long max = maxProSubArr(arr,len);
    cout<<max<<endl;
}