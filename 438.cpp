#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool map_cmp(map<int,int> &s,map<int,int> &p)
    {
        map<int,int> ::iterator it1,it2;
        if(s.size()!=p.size())
        {
            return false;
        }
        for(it1=s.begin(),it2=p.begin() ;it1!=s.end(),it2!=p.end() ;it1++,it2++)
        {
            if(it1->first!=it2->first || it1->second!=it2->second)
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        int i;
        int len = p.length();
        map<int,int> p_cons;
        map<int,int> s_cons;
        for(i=0;i<len;i++)
        {
            p_cons[p[i]]++;
        }
        for(i=0;i<len;i++)
        {
            s_cons[s[i]]++;
        }
        for(;i<s.length();i++)
        {
            if(map_cmp(p_cons,s_cons))
            {
                result.push_back(i-len);
            }
            s_cons[s[i]]++;
            s_cons[s[i-len]]--;
            if(s_cons[s[i-len]]==0)
            {
                s_cons.erase(s[i-len]);
            }
        }
        if(map_cmp(p_cons,s_cons))
        {
            result.push_back(i-len);
        }

        return result;
    }
};

int main()
{

    return 0;
}
