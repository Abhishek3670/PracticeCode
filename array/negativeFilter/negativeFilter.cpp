#include <iostream>
using namespace std;
void printArray(int arr[] , int n)
{
    for(int i = 0 ; i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void negativeFilter(int arr[] , int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            if(i != j)
                swap(arr[i],arr[j]);
            j++;
        }
       
    }
    
     
}
int main(){
    int arr [] = {1,-1,-5,5,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Before filter" << std::endl;
    printArray(arr,len);
    std::cout << "After filter" << std::endl;
    negativeFilter(arr,len);
    printArray(arr,len);
}