#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int,int> &a, const pair<int,int> &b)
    {
        if(a.first==b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }

    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people)
    {
        vector<pair<int, int> > result;
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<people.size();i++)
        {
            result.insert(result.begin()+people[i].second,people[i]);
        }
        return result;
    }
};

int main()
{
    return 0;
}
