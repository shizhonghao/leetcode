#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s)
    {
        int len = s.length();
        int cnt = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;i-j>=0 && i+j<len;j++)
            {
                if(s[i-j]==s[i+j])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            for(int j=0;i-j>=0 && i+j+1<len;j++)
            {
                if(s[i-j]==s[i+j+1])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}
