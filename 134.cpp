#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        vector<int> change;
        for(int i=0;i<gas.size();i++)
        {
            change.push_back(gas[i]-cost[i]);
        }
        int result = 0;
        int sum = 0,max_sum = 0;
        for(int i=0;i<change.size();i++)
        {
            sum += change[i];
            if(sum>max_sum)
            {
                max_sum = sum;
                result = 1;
            }
        }
        if(sum<0)
        {
            return -1;
        }
        return result;
    }
};

int main()
{
    return 0;
}
