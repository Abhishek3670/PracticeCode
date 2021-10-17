#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
// commmom between 2 or 3 array;
void commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    unordered_set<int> setA, setB, setC;
    for (int i = 0; i < n1; i++)
        setA.insert(A[i]);
    for (int i = 0; i < n2; i++)
        setB.insert(B[i]);
    for (int i = 0; i < n3; i++)
    {
        if (setA.find(C[i]) != setA.end() && setB.find(C[i]) != setB.end())
        {
            setC.insert(C[i]);
        }
    }
    unordered_set<int>::iterator itr;
    for (itr = setC.begin(); itr != setC.end(); itr++)
        cout << *itr << endl;
}
int main()
{
    int arr1[] = {1, 5, 10, 20, 40, 80, 20, 20};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int len3 = sizeof(arr3) / sizeof(arr3[0]);

    commonElements(arr1, arr2, arr3, len1, len2, len3);
}