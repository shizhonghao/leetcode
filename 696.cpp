#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s)
    {
        int result = 0;
        int cnt[3] = {0,0,0};
        s+="2";
        cnt[s[0]-'0']++;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=s[i-1])
            {
                result += min(cnt[0],cnt[1]);
                cnt[s[i]-'0'] = 0;
            }
            cnt[s[i]-'0']++;
        }
        return result;
    }
};

int main()
{
    return 0;
}
