#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
// this one is wrong for test case "abbbbbbbbbbb" , "aaaaaaaaaaab";
bool isAnagram2(string &a, string &b)
{
    int n1 = a.size();
    int n2 = b.size();
    if (n1 != n2)
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n1; i++)
        if (a[i] != b[i])
            return false;
    return true;
}
bool isAnagram(string &a, string &b)
{
    if (a == b)
        return true;
    int n = a.size();
    int m = b.size();
    if (n != m)
        return false;
    map<char, int> map;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
        map[b[i]]++;
    }

    for (auto &i : map)
        if (i.second % 2 != 0)
            return false;
    return true;
}
bool solve(string a, string b)
{
    vector<int> freq(26, 0);
    for (const auto &ele : a)
    {
        freq[ele - 'a']++;
    }
    for (const auto &ele : b)
    {
        freq[ele - 'a']--;
    }
    return all_of(freq.begin(), freq.end(), [](const int &x)
                  { return x == 0; });
}
int main()
{
    string a = "abbbbbbbbbbb";
    string b = "aaaaaaaaaaab";

    cout << isAnagram(a, b) << endl;
    cout << isAnagram2(a, b) << endl;
    cout << solve(a, b);
}