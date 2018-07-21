#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int result = nums.size()+1;
        int l = 0, r = 0,sum = 0;
        while(r<nums.size())
        {
            sum += nums[r];
            r++;
            while(sum>=s)
            {
                result = min(result, r-l);
                sum -= nums[l];
                l++;
            }
        }

        if(result==nums.size()+1)
        {
            return 0;
        }
        return result;
    }
};
int main()
{
    return 0;
}

