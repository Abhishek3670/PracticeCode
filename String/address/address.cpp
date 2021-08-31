#include <iostream>

using namespace std;

int main()
{
    string s = "ftpsunrurururu";
    int n = s.size();
    string protocol = "";
    string context = "";
    string domain = "";
    int i;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'h' && i == 0)
            while (i < 4)
            {
                protocol += s[i];
                i++;
            }

        else if (s[i] == 'f' && i == 0)
            while (i < 3)
            {
                protocol += s[i];
                i++;
            }
        if (s[i] == 'r' && s[i + 1] == 'u')
            break;
        else
            domain += s[i];
        j = i;
    }
    j += 3;
    while (j < n)
    {
        context += s[j];
        j++;
    }

    string c = protocol + "://" + domain + ".ru" + "/" + context;
    cout << c;
}