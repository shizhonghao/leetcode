#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool valid(string s)
    {
        stack<int> stk;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                stk.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!stk.empty())
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

    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> result;
        queue<string> q;
        set<string> has;
        q.push(s);
        int found = 0;
        while(!q.empty())
        {
            string str = q.front();
            q.pop();
            if(valid(str))
            {
                result.push_back(str);
                found = 1;
            }
            if(found)
            {
                continue;
            }

            int l=0,r=0;
            for(int i=0;i<str.length();i++)
            {
                if(str[i]=='(')
                {
                    l++;
                }
                else if(str[i]==')')
                {
                    r++;
                }
            }
            char ch_erase;
            if(l>r)
            {
                ch_erase = '(';
            }
            else
            {
                ch_erase = ')';
            }
            for(int i=0;i<str.length();i++)
            {
                if(str[i]==ch_erase)
                {
                    string newstr = str.substr(0,i)+str.substr(i+1);
                    if(has.count(newstr)==0)
                    {
                        q.push(newstr);
                        has.insert(newstr);
                    }
                }
            }
        }


        return result;
    }
};

int main()
{
    return 0;
}
