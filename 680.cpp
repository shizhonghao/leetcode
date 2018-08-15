#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool valid(string s)
    {
        int len = s.length();
        for(int i=0;i<len/2+1;i++)
        {
            if(s[i]!=s[len-1-i])
            {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int len = s.length();
        for(int i=0;i<len/2+1;i++)
        {
            if(s[i]!=s[len-1-i])
            {
                bool result = valid(s.substr(i,len-2*i-1));
                result |= valid(s.substr(i+1,len-2*i-1));
                return result;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
