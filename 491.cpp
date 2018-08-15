#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int>& nums)
    {
        set<vector<int> > s;
        set<vector<int> > ::iterator it;
        vector<vector<int> > result;
        for(int i=nums.size()-1;i>=0;i--)
        {
            set<vector<int> > cpy = s;
            for(it=cpy.begin();it!=cpy.end();it++)
            {
                vector<int> tmp = *it;
                if(tmp[0]>=nums[i])
                {
                    tmp.insert(tmp.begin(),nums[i]);
                    s.insert(tmp);
                }
            }

            vector<int> v(1,nums[i]);
            s.insert(v);
        }
        for(it=s.begin();it!=s.end();it++)
        {
            vector<int> tmp = *it;
            if(tmp.size()!=1)
            {
                result.push_back(tmp);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
