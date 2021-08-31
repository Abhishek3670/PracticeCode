
#include <bits/stdc++.h>
using namespace std;

void sortString(string &str)
{
    sort(str.begin(), str.end());
    cout << str;
}
string sortk(string s, int k)
{
    if (isupper(s.at(k - 1)))
    {
        sortString(s);
        sortk(s,k);
    }
    s.erase(s.at(k-1));
    
}
int main()
{
    string s = "fEdCbA";
    int k = 6;
    string news = sortk(s, k);
    cout << news << endl;
    return 0;
}
