#include <iostream>
using namespace std;
void printArray(int arr[] , int n)
{
    for(int i = 0 ; i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void maxElement(int arr[] , int n)
{
    int tempo = 0;
    int max=  arr[0];
    int i = 0;
    while (i<n)
    {
        if(arr[i] > max )
        max = arr[i];

        i++;
    }
    cout<<"Maximum element: "<<max<<endl;
}
void minElement(int arr[] , int n)
{
    int tempo = 0;
    int min=  arr[0];
    int i = 0;
    while (i<n)
    {
        if(arr[i] < min )
        min = arr[i];

        i++;
    }
    cout<<"Minimum element: "<<min<<endl;
}

int main() {
    int arr[] = {12,41,74,02,00};
    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,len);
    maxElement(arr,len);
    minElement(arr,len);

}