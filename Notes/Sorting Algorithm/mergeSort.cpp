#include <iostream>
using namespace std;
void printArray(int arr[],int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void merge(int array[],int left, int mid, int right)
{
     int tempArray[right-left+1];
        int pos=0;
        int begin = left;
        int index = mid + 1;
        while(begin <= mid && index <= right)
        {
                if(array[begin] < array[index])
                {
                    tempArray[pos++] = array[begin++];
                }
                else
                {
                        tempArray[pos++] = array[index++];
                }
        }
        while(begin <= mid)  
            tempArray[pos++] = array[begin++];
        while(index <= right)
            tempArray[pos++] = array[index++];
        int iter;
        for(iter = 0;iter < pos; iter++)
        {
                array[iter+left] = tempArray[iter];
        }
        return;
}
void mergeSort(int arr[] , int left , int right){
    int mid = (left + right)/2;
    if(left < right){
        mergeSort(arr,left , mid);
        mergeSort(arr,mid + 1 , right );
        merge(arr,left,mid,right);
    }  
    return;
}
int main()
{
    int arr[] = {5,4,3,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "Before Sort"<< beginl;
    printArray(arr, len);
    cout << beginl;
    mergeSort(arr,0,len-1);
    cout << "After Sort"<< beginl;
    printArray(arr, len); 
}