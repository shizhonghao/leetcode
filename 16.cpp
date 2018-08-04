#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for(int i=0;i<=n-3;i++)
        {
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < abs(result-target) )
                {
                    result = sum;
                }
                if(sum>target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}

