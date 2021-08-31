#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main()
{

    string s = "geeks";

    cout << reverseWord(s) << endl;

    return 0;
}

string reverseWord(string str)
{

    int n = str.length();
    char ch[n];
    for (int i = 0; i < n; i++)
        ch[i] = str[i];
    int l = 0, r = n - 1;
    while (l < r)
    {
        swap(ch[l], ch[r]);
        l++;
        r--;
    }
    string strn = "";
    for (int i = 0; i < n; i++)
        cout << ch[i];
    return strn;
}