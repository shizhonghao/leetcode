#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> result;

    void dfs(string s,int cuts,string rest)
    {
        int len = rest.length();
        if((cuts)*3<len || (cuts)*1>len )
        {
            return;
        }
        if(cuts==1)
        {
            if(rest[0]=='0' && len>1)
            {
                return;
            }
            int ip = atoi(rest.c_str());
            if(ip<=255)
            {
                result.push_back(s+rest);
            }
        }
        else
        {
            if(rest[0]=='0')
            {
                dfs(s+"0.",cuts-1,rest.substr(1));
                return;
            }
            for(int i=1;i<=3 && i<rest.length();i++)
            {
                int ip = atoi(rest.substr(0,i).c_str());
                if(ip<=255)
                {
                    dfs(s+rest.substr(0,i)+'.',cuts-1,rest.substr(i));
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        dfs("",4,s);/*
        for(int i=1;i<=3 && i<s.length();i++)
        {
            int ip = atoi(s.substr(0,i).c_str());
            if(ip<=255)
            {
                dfs(s.substr(0,i)+'.',3,s.substr(i));
            }
        }*/
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> res = s.restoreIpAddresses("01300");
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
