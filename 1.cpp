#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int,int> sub;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            int x = target - nums[i];
            if(sub[x]>0)
            {
                result.push_back(sub[x]-1);
                result.push_back(i);
                return result;
            }
            sub[nums[i]] = i+1;
        }

    }
};

int main()
{
    return 0;
}
