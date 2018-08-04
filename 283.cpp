#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int zerocnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zerocnt++;
            }
            else
            {
                nums[i-zerocnt] = nums[i];
            }
        }
        for(int i=n-1;i+zerocnt>=n;i--)
        {
            nums[i] = 0;
        }
    }
};

int main()
{
    return 0;
}

