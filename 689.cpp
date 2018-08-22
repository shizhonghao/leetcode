#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        vector<int> result(3,0);
        int len = nums.size();
        int sum[len];
        memset(sum,0,sizeof(sum));
        for(int i=0;i<k;i++)
        {
            sum[0] += nums[i];
        }
        for(int i=1;i<len-k+1;i++)
        {
            sum[i] = sum[i-1]-nums[i-1]+nums[i+k-1];
        }

        int left[len];
        int right[len];
        int best = 0;
        for(int i=0;i<len-k+1;i++)
        {
            if(sum[i]>sum[best])
            {
                best = i;
            }
            left[i] = best;
        }

        best = len-k;
        for(int i=best;i>=0;i--)
        {
            if(sum[i]>sum[best])
            {
                best = i;
            }
            right[i] = best;
        }

        best = 0;
        for(int b=k;b<len-k-k+1;b++)
        {
            int a = left[b-k],c = right[b+k];
            if(sum[a]+sum[b]+sum[c]>best)
            {
                best = sum[a]+sum[b]+sum[c];
                result[0] = a;
                result[1] = b;
                result[2] = c;
            }
        }

        /*
        vector<int> result;
        int len = nums.size();
        int sum[len];
        int dp[len][3];
        int dp_last[len][3];
        memset(dp,0,sizeof(dp));
        memset(dp_last,0,sizeof(dp_last));
        memset(sum,0,sizeof(sum));
        for(int i=0;i<k;i++)
        {
            sum[0] += nums[i];
        }
        for(int i=1;i<len-k+1;i++)
        {
            sum[i] = sum[i-1]-nums[i-1]+nums[i+k-1];
        }
        dp[0][0] = sum[0];
        for(int j=0;j<3;j++)
        {
            for(int i=1;i<len-k+1;i++)
            {
                if(sum[i]>dp[i-1][0])
                {
                    dp[i][0] = sum[i];
                    dp_last[i][0] = i;
                }
                else
                {
                    dp[i][0] = dp[i-1][0];
                    dp_last[i][0] = dp_last[i-1][0];
                }
            }
        }
        */


        return result;
    }
};

int main()
{
    return 0;
}
