#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n = nums.size();
        if(nums.size()==1)
        {
            return 0;
        }
        if(nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        int l = 0,r = n-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>nums[mid+1])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main()
{
    return 0;
}
