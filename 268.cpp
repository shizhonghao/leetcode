#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int result = 0;
        for(int i=0;i<nums.size();i++)
        {
            result ^= nums[i];
            result ^= i+1;
        }
        return result;
    }
};

int main()
{
    return 0;
}
