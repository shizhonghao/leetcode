#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[' || s[i]=='(' || s[i]=='{')
            {
                stk.push(s[i]);
            }
            else
            {
                char rev;
                if(s[i]==')')
                {
                    rev = '(';
                }
                else if(s[i]==']')
                {
                    rev = '[';
                }
                else if(s[i]=='}')
                {
                    rev = '{';
                }

                if(!stk.empty() && stk.top()==rev)
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(stk.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
