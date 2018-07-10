#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int i;
        int turn_val,turn_point = -1;
        for(i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                turn_val = nums[i];
                turn_point = i;
                break;
            }
        }
        if(turn_point==-1)
        {
            int len = nums.size();
            for(int j=0;j<len/2;j++)
            {
                swap(nums[j],nums[len-1-j]);
            }
            return;
        }
        for(i=turn_point+1;i<nums.size();i++)
        {
            if(nums[i]>turn_val)
            {
                swap(nums[i],nums[turn_point]);
            }
        }
        for(;i<nums.size();i++)
        {
            if(nums[i]>turn_val && nums[i]<nums[turn_point])
            {
                swap(nums[i],nums[turn_point]);
            }
        }
        sort(nums.begin()+turn_point+1,nums.end());
        return;
    }
};

int main()
{

    return 0;
}
