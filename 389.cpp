#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t)
    {
        map<int,int> cnt;
        for(int i=0;i<s.length();i++)
        {
            cnt[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            cnt[t[i]]--;
            if(cnt[t[i]]==-1)
            {
                return t[i];
            }
        }
    }
};

int main()
{
    return 0;
}
