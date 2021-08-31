#include <iostream>
#include <math.h>
using namespace std;
void egyptionFraction(int nr, int dr)
{
    if (nr % dr == 0)
    {
        cout << (nr / dr);
        return;
    }

    if (nr == 0 || dr == 0)
        return;
    if (dr % nr == 0)
    {
        cout << "1/" << dr / nr;
        return;
    }
    int n = 1 + dr / nr;
    cout << "1/" << n << " + ";
    egyptionFraction(nr * n - dr, dr * n);
}
int main()
{
    int nr = 4;
    int dr = 6;

    egyptionFraction(nr, dr);
    return 0;
}