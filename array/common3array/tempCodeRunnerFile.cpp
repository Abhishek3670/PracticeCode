void commonElement(int arr1[], int arr2[], int arr3[], int len1, int len2, int len3)
{
    map<int, int> m;
    for (int i = 0; i < len1; i++)
        m[arr1[i]]++;
    for (int i = 0; i < len2; i++)
        m[arr2[i]]++;
    for (int i = 0; i < len3; i++)
        m[arr3[i]]++;
   map<int, int>:: iterator itr;
   for (itr = m.begin(); itr != m.end(); itr++)
    if((*itr).second > 1)
        cout<<(*itr).first << endl; 
}