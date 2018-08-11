#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.count(nums[i])==0)
            {
                s.insert(nums[i]);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
