#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges)
    {
        if(n==1)
        {
            vector<int> res(1);
            return res;
        }
        vector<int> result;
        vector<int> adj[n];
        queue<int> q;
        int visited[n];
        int degree[n];
        memset(visited,0,sizeof(visited));
        memset(degree,0,sizeof(degree));
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while(cnt<n)
        {
            result.clear();
            int c = q.size();
            for(int i=0;i<c;i++)
            {
                int node = q.front();
                result.push_back(node);
                q.pop();
                cnt++;
                for(int j=0;j<adj[node].size();j++)
                {
                    int next = adj[node][j];
                    degree[next]--;
                    if(degree[next]==1)
                    {
                        q.push(next);
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
