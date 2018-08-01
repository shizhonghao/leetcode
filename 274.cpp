#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int result = 0;
        int n = citations.size();
        if(n==0)
        {
            return 0;
        }
        sort(citations.begin(),citations.end());
        if(citations[n-1]==0)
        {
            return 0;
        }
        int l = 0,r = n-1;
        while(l<r)
        {
            int mid = (l+r)/2;
            //cout << l << ' ' << r << endl;
            if(citations[mid]==n-mid)
            {
                return n-mid;
            }
            else if(citations[mid]<n-mid)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        result = n-l;
        return result;
    }
};

int main()
{
    return 0;
}

