#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "Thiweqeqs isqwedq correfsdfsfwct.....";
    if (isupper(str[0]) && str[str.size() - 1] == '.')
        cout << true;
    else
        cout << false;
}