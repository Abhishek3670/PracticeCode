#include <iostream>
#include <set>
#include <unordered_map>
#include <string.h>

using namespace std;

int longestUniqueSubsttrOk1(string str)
{
   int n = str.length();
        int cur_len = 1;  
        int max_len = 1;  
        int prev_index;  
        int i;
        int visited[26];
     
        for (i = 0; i < 26;  i++)
            visited[i] = -1;
        
       
        for (i = 1; i < n; i++)
        {
            // cout << str[i]-'a' <<endl;   
            prev_index =  visited[str[i]-'a'];
     
            if (prev_index == -1 || i - cur_len > prev_index)
                cur_len++;
     
            else
            {
                if (cur_len > max_len)
                    max_len = cur_len;
     
                cur_len = i - prev_index;
            }
     
            visited[str[i]-'a'] = i;
        }
     
        if (cur_len > max_len)
            max_len = cur_len;
     
      
        return max_len;
}
int LongestUniqueSubsttrOn(string str){
    int l = 0;
    int r = 0;
    int len = 0;
    int maxlen = 0;
    set<char> s;
   while(r < str.length())
   {
        if ( s.find(str[r]) != s.end() )
        {       
            s.erase(str[l]);
            l++;
            len--;
        }
        else {
            len ++;
            maxlen = max ( maxlen , len) ;
            s.insert(str[r]);
            r++;
        }

    }
    return maxlen;
}
// not working
int LongestUniqueSubsttrOk2(string s){
     int n=s.size();
        unordered_map<char,int>mp;
        int mx=-1,i=0,j=0;
        while(j<n)
        {
            mp[s[j]]
            if(mp[s[j]]==1)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else
            {
                while(mp[s[j]!=1])
                {
                    mp[s[i]]--;
                    i++;
                }
                mx=max(mx,j-i+1);
                j++;
            }
        }
        return mx;
}
int main()
{
    string s = "geeksforgeeks";
    cout << LongestUniqueSubsttrOk2(s);
    return 0;
}