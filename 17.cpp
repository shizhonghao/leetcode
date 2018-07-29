#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<char> > mapping = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},
    {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if(digits.length()==0)
        {
            return result;
        }
        queue<string> q;
        q.push("");
        for(int i=0;i<digits.length();i++)
        {
            int button = digits[i]-'0';
            if(button>=2 && button<=9)
            {
                int cnt = q.size();
                while(cnt--)
                {
                    string last = q.front();
                    q.pop();
                    for(int j=0;j<mapping[button].size();j++)
                    {
                        char ch = mapping[button][j];
                        q.push(last+ch);
                    }
                }

            }
        }
        while(!q.empty())
        {
            string res = q.front();
            q.pop();
            result.push_back(res);
        }
        return result;
    }
};

int main()
{
    return 0;
}
