#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        if(p.length()==0)
        {
            if(s.length()==0)
            {
                return true;
            }
            return false;
        }

        bool match = false;
        if(s.length()!=0)
        {
            if(s[0]==p[0] || p[0]=='.')
            {
                match = true;
            }
        }

        if(p.length()>=2 && p[1]=='*')
        {
            return isMatch(s,p.substr(2)) || (match && isMatch(s.substr(1),p));
        }
        else
        {
            return match && isMatch(s.substr(1),p.substr(1));
        }
    }
};

int main()
{

    return 0;
}
