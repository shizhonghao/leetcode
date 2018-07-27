#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[30][30];

    int first_player_wins(vector<int> nums)
    {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return abs(nums[0]-nums[1]);
        }
        vector<int> nl(nums),nr(nums);
        nl.erase(nl.begin());
        nr.erase(nr.begin()+n-1);
        return max(nums[0]-first_player_wins(nl), nums[n-1]-first_player_wins(nr));
    }

    bool PredictTheWinner(vector<int>& nums)
    {
        int n = nums.size();
        if(n<=1)
        {
            return true;
        }
        for(int i=0;i<n;i++)
        {
            dp[i][i] = nums[i];
            for(int j=i-1;j>=0;j--)
            {
                int l = j;
                int r = i;
                dp[l][r] = dp[r][l] = max(nums[l]-dp[l+1][r], nums[r]-dp[l][r-1]);
            }
        }
        return dp[0][n-1];
        return first_player_wins(nums,0,)<0 ? false : true;
    }
};

int main()
{
    return 0;
}




