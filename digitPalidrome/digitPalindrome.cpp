// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isDigitSumPalindrome(int N)
    {
        int newNum = 0;
        // Finding out the digit sum
        while (N)
        {
            newNum += N % 10;
            N /= 10;
        }
        int reversedNewNum = 0;
        N = newNum;
        // Reversing N and storing it in reversedNewNum
        while (N)
        {
            reversedNewNum = (reversedNewNum * 10) + (N % 10);
            N /= 10;
        }
        return reversedNewNum == newNum;
    }
};

// { Driver Code Starts.
int main()
{
    int t = 1;
    while (t--)
    {
        int N = 7564;

        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}