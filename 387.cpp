#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s)
    {
        int result = s.length()+1;
        char ch;
        map<char,int> last;
        map<char,int> cnt;
        map<char,int> ::iterator it;
        for(int i=0;i<s.length();i++)
        {
            last[s[i]] = i;
            cnt[s[i]]++;
        }
        for(it=cnt.begin();it!=cnt.end();it++)
        {
            if(it->second==1)
            {
                if(last[it->first]<result)
                {
                    result = last[it->first];
                }
            }
        }
        if(result == s.length()+1)
        {
            result = -1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.firstUniqChar("loveleetcode") << endl;
    return 0;
}
