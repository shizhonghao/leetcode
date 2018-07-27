#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int result = 0;
        int n = ratings.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        vector<int> give(n,1);

        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                give[i] = give[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                give[i] = max(give[i],give[i+1]+1);
            }
        }

        for(int i=0;i<n;i++)
        {
            cout << give[i] << " ";
            result += give[i];
        }
        return result;
    }
};

int main()
{
    return 0;
}


