#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages)
    {
        int result = 0;
        int cnt[130];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<ages.size();i++)
        {
            cnt[ages[i]]++;
        }
        for(int i=15;i<=120;i++)
        {
            if(cnt[i]>0)
            {
                for(int j=8+i/2;j<i;j++)
                {
                    result += cnt[i]*cnt[j];
                }
                result += cnt[i]*(cnt[i]-1);
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}
