#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(int N,int has[],int i)
    {
        if(i==N+1)
        {
            return 1;
        }
        int cnt = 0;
        for(int j=1;j<=N;j++)
        {
            if(has[j]==1 && (i%j==0||j%i==0) )
            {
                has[j] = 0;
                cnt += dfs(N,has,i+1);
                has[j] = 1;
            }
        }
        return cnt;
    }

    int countArrangement(int N)
    {
        int cnt = 0;
        int has[N+1];
        for(int i=1;i<=N;i++)
        {
            has[i] = 1;
        }
        cnt = dfs(N,has,1);
        return cnt;
    }
};

int main()
{
    return 0;
}
