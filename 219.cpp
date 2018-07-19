#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        map<int,int> last;
        for(int i=0;i<nums.size();i++)
        {
            if(last.count(nums[i])!=0)
            {
                if(i-last[nums[i]]<=k)
                {
                    return true;
                }
            }
            last[nums[i]] = i;
        }
        return false;
    }
};

int main()
{

    return 0;
}
