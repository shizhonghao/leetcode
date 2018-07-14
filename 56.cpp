#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for an interval.
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    bool mergeable(Interval a,Interval b)
    {
        //cout << a.start << b.start << a.end << b.end << endl;
        if(a.end+1>=b.start)
        {
            return true;
        }
        return false;
    }

    Interval merge_two(Interval a,Interval b)
    {
        return Interval(min(a.start,b.start),max(a.end,b.end));
    }

    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        map<int,int> in;
        map<int,int> ::iterator it;
        for(int i=0;i<intervals.size();i++)
        {
            Interval tmp = intervals[i];
            it = in.lower_bound(tmp.start);
            if(it!=in.end())
            {
                int l = it->first;
                int r = it->second;
                //cout << "not last:" << l << " " << r << endl;
                if(mergeable(tmp,Interval(l,r)))
                {
                    in.erase(it);
                    tmp = merge_two(intervals[i],Interval(l,r));
                }
            }
            it = in.lower_bound(tmp.start);
            if(it!=in.begin())
            {
                it--;
                int l = it->first;
                int r = it->second;
                //cout << "not first:" << l << " " << r <<  " " << tmp.start << " " << tmp.end << endl;
                if(mergeable(Interval(l,r),tmp))
                {
                    tmp = merge_two(tmp,Interval(l,r));
                    in.erase(it);
                }
            }
            in[tmp.start] = tmp.end;
            //cout << "added:" << tmp.start << " " << tmp.end << endl;
        }
        for(it=in.begin();it!=in.end();it++)
        {
            result.push_back(Interval(it->first,it->second));
        }
        return result;
    }
};

int main()
{

    return 0;
}
