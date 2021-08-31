#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
void display(vector<int> &v)
{
    vector<int>::iterator i;
    
    for ( i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
int main(int argc, const char **argv)
{
    
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
  
    sort(v.begin(), v.end());
  
    cout << "Sorted \n";
    display(v);
  
    return 0;
}