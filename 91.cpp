#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
        int len = s.length();
        if(len==0)
        {
            return 0;
        }
        int dp[len+1];
        dp[0] = 1;
        if(s[0]=='0')
        {
            dp[0] = 0;
        }
        for(int i=1;i<len;i++)
        {
            int last = (s[i]-'0')+(s[i-1]-'0')*10;
            if(last==0)
            {
                dp[i] = 0;
            }
            else if(last%10==0)
            {
                if(last>20)
                {
                    dp[i] = 0;
                }
                else if(i==1)
                {
                    dp[i] = 1;
                }
                else if(last<30)
                {
                    dp[i] = dp[i-2];
                }
            }
            else if(last<10)
            {
                dp[i] = dp[i-1];
            }
            else if(last>26)
            {
                dp[i] = dp[i-1];
            }
            else
            {
                if(i==1)
                {
                    dp[i] = 2;
                }
                else
                {
                    dp[i] = dp[i-1]+dp[i-2];
                }
            }
        }
        return dp[len-1];
    }
};

int main()
{
    return 0;
}
