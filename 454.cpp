#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        int result = 0;
        map<int,int> cnt1,cnt2;
        map<int,int> ::iterator it;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                cnt1[A[i]+B[j]]++;
            }
        }
        for(int i=0;i<C.size();i++)
        {
            for(int j=0;j<D.size();j++)
            {
                cnt2[C[i]+D[j]]++;
            }
        }

        for(it=cnt1.begin();it!=cnt1.end();it++)
        {
            int num = it->first;
            if(cnt2.count(-num)>0)
            {
                result += it->second*cnt2[-num];
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
