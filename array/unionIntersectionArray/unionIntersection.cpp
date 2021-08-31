#include <iostream>
using namespace std;
void unionArray(int arr_1[], int arr_2[], int len_1, int len_2)
{
    int unionArray[len_1 + len_2] = {0};
    int count = 0;
    for (int i = 0; i < len_1; i++ )
    {
        unionArray[count] = arr_1[i];
        count++;
    }
    for(int i = 0 ; i<len_1; i++)
    {
        for(int j = 0 ; j < len_2 ; j++)
        {
            if(arr_2[j] == arr_1[i])
            {
                j++;                
            }
            unionArray[count] = arr_2[j];
            count++;
        }
    }
    for (int j = 0; j < count; j++)
    {
        cout << unionArray[j] << "  ";
    }
}
void intersectArray(int arr_1[], int arr_2[], int len_1, int len_2)
{
    int intersectionArray[len_1 + len_2] = {0};
    int count = 0;
    for (int i = 0; i < len_1; i++)
    {
        for (int j = 0; j < len_2; j++)
        {
            if (arr_1[i] == arr_2[j])
            {
                intersectionArray[count] = arr_1[i];
                count++;
            }
        }
    }
    for (int j = 0; j < count; j++)
    {
        cout << intersectionArray[j] << " ";
    }
}
int main()
{
    int arr_1[] = {0, 1, 2, 3, 5};
    int arr_2[] = {0, 2, 4, 5, 6};
    int len_1, len_2;
    len_1 = sizeof(arr_1) / sizeof(arr_1[0]);
    len_2 = sizeof(arr_2) / sizeof(arr_2[0]);
    unionArray(arr_1, arr_2, len_1, len_2);
    cout << endl;
    intersectArray(arr_1, arr_2, len_1, len_2);
}