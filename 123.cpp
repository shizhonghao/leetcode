#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int result = 0;
        int n = prices.size();
        if(n==0)
        {
            return 0;
        }
        int lmax[n];
        int rmax[n];
        int minp = prices[0],maxp = prices[n-1];
        lmax[0] = rmax[n-1] = 0;
        for(int i=1;i<n;i++)
        {
            lmax[i] = max(lmax[i-1],prices[i]-minp);
            minp = min(minp,prices[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rmax[i] = max(rmax[i+1],maxp-prices[i]);
            maxp = max(maxp,prices[i]);
        }
        result = lmax[n-1];
        for(int i=1;i<n-2;i++)
        {
            result = max(result,rmax[i+1]+lmax[i]);
        }
        return result;
    }
};


int main()
{
    return 0;
}
