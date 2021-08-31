 int i = n;
    int j = m;
    string ss = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ss = ss + x[i - 1];
            i--;
            j--;
        }
        else if (t[i - 1][j] <= t[i][j - 1])
        {
            ///ss = ss + x[i - 1];
            j--;
        }

        else
        {
            //ss = ss + y[j - 1];
            i--;
        }
    }
    reverse(ss.begin(), ss.end());