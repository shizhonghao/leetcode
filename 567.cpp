#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<char,int> cnt1,cnt2;

    bool is_perm()
    {
        map<char,int> ::iterator it;
        for(it=cnt1.begin();it!=cnt1.end();it++)
        {
            char key = it->first;
            int val = it->second;
            if(cnt2.count(key)==1)
            {
                if(val==cnt2[key])
                {
                    continue;
                }
            }
            return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();

        for(int i=0;i<len1;i++)
        {
            cnt1[s1[i]]++;
            cnt2[s2[i]]++;
        }
        for(int i=len1;i<len2;i++)
        {
            if(is_perm())
            {
                return true;
            }
            cnt2[s2[i]]++;
            cnt2[s2[i-len1]]--;
            if(cnt2[s2[i-len1]]==0)
            {
                cnt2.erase(s2[i-len1]);
            }
        }
        if(is_perm())
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

