#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> father;

    int find_father(int x)
    {
        return father[x]==x ? x : father[x]=find_father(father[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        vector<int> result;
        int n = edges.size();
        for(int i=0;i<=n;i++)
        {
            father.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int f1 = find_father(u);
            int f2 = find_father(v);
            if(f1==f2)
            {
                result.push_back(u);
                result.push_back(v);
                return result;
            }
            else
            {
                father[f1] = f2;
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}

