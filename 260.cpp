#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> result;
        int a = 0,b = 0,xor_sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            xor_sum ^= nums[i];
        }
        int pow_of_2 = 1;
        while(!(pow_of_2&xor_sum))
        {
            pow_of_2 <<= 1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(pow_of_2&nums[i])
            {
                a ^= nums[i];
            }
        }
        b = a^xor_sum;
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};

int main()
{
    return 0;
}

