#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        string str;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]<='z' && s[i]>='a')||(s[i]<='9' && s[i]>='0'))
            {
                str += s[i];
            }
            if(s[i]<='Z' && s[i]>='A')
            {
                str += s[i]+('a'-'A');
            }
        }
        for(int i=0;i<str.size()/2+1;i++)
        {
            if(str[i]!=str[str.length()-i-1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
