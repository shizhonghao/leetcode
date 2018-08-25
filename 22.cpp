#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> result;

    void dfs(string s,int l,int r,int n)
    {
        if(l+r==2*n)
        {
            result.push_back(s);
            return ;
        }

        if(l<n)
        {
            dfs(s+"(",l+1,r,n);
        }
        if(r<l)
        {
            dfs(s+")",l,r+1,n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        dfs("",0,0,n);
        return result;
    }
};

int main()
{
    return 0;
}
