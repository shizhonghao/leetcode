#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int result = 0;
        int array_size = nums.size();
        map<int,int> cnt;
        int sum = 0;
        cnt[0] = 1;
        for(int i=0;i<array_size;i++)
        {
            sum += nums[i];
            cnt[sum]++;
            result += cnt[sum-k];
        }
        return result;
    }
};

int main()
{

    return 0;
}
