#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > result;
        map<int,int> cnt;
        map<int,int> ::iterator l;
        map<int,int> ::reverse_iterator r;
        for(int i=0;i<nums.size();i++)
        {
            cnt[nums[i]]++;
        }
        for(l=cnt.begin();l!=cnt.end() && l->first<0;l++)
        {
            for(r=cnt.rbegin();r!=cnt.rend() && r->first>0;r++)
            {
                vector<int> solution;
                int small = l->first;
                int large = r->first;
                int mid = -(small + large);
                if(cnt.count(mid)==0)
                {
                    continue;
                }
                if(mid<small)
                {
                   continue;
                }
                if(mid==small && cnt[mid]<2)
                {
                   continue;
                }
                if(mid>large)
                {
                    break;
                }
                if(mid==large && cnt[mid]<2)
                {
                    break;
                }
                solution.push_back(small);
                solution.push_back(mid);
                solution.push_back(large);
                result.push_back(solution);
            }
        }
        if(cnt[0]>=3)
        {
            vector<int> solution(3);
            result.push_back(solution);
        }
        return result;
    }
};

int main()
{

    return 0;
}
