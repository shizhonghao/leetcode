#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        queue<int> q;
        q.push(0);
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum%2==1)
        {
            return false;
        }
        int half = sum/2;
        bool has[sum+1];
        memset(has,0,sizeof(has));
        for(int i=0;i<nums.size();i++)
        {
            int x = 1;
            //cout << i << " " << nums[i] << endl;
            while(x!=0)
            {
                x = q.front();
                q.pop();
                //cout << x << endl;
                int s = x+nums[i];
                if(!has[s])
                {
                    has[s] = 1;
                    q.push(s);
                    if(half==s)
                    {
                        return true;
                    }
                }
                q.push(x);
            }
        }
        return false;
    }
};
int main()
{
    return 0;
}

