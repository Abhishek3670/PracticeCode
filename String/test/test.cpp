#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;
string convert(string s, int numRows)
{
    char mat[numRows][13];
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < 13; j++)
            mat[i][j] = 'a';

    string ans = "";
    int i = 0, j = 0, k = 0;
    int n = s.length();
    while (k < n)
    {
        if ((j == 0 || j == 3 || j == 6) && i < numRows)
        {
            
            mat[i][j] = s[k];
            i++;
            k++;
        }
        else if (i > 1)
        {
            cout << "sdsd";
            if ((j == 0 || j == 3 || j == 6))
                i--;
            i--;
            j++;
            mat[i][j] = s[k];
            k++;
        }
    }
    for (int i = 0; i < numRows; i++)
        for (int j = 0; j < 13; j++)
            if (mat[i][j] != 'a')
                ans+= mat[i][j];
    return ans;
}
int main()
{
    // string s = "hella";
    // cout << s.find("e");
    // unordered_map<char, char> map{
    //     {'(', ')'},
    //     {'{', '}'},
    //     {'[', ']'},
    // };
    // unordered_map<char, char>::iterator itr;
    // itr = map.find("e");
    // if (itr != map.end())
    //     cout << 1;
    cout << convert("PAYPALISHIRING" , 3);
}