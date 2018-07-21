#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        if(n<=2)
        {
            return false;
        }
        stack<int> s;
        int min_val[n];
        min_val[0] = nums[i];
        for(int i=1;i<n;i++)
        {
            min_val[i] = min(min_val[i-1],nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>min_val[i])
            {
                while(!s.empty() && s.top()<=min_val[i])
                {
                    s.pop();
                }
                if(!s.empty() && s.top()<nums[i])
                {
                    return true;
                }
                s.push(nums[i]);
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}
