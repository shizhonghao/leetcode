#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool mutate(string a,string b)
    {
        int cnt=0;
        for(int i=0;i<8;i++)
        {
            if(a[i]!=b[i])
            {
                cnt++;
            }
        }
        return cnt==1;
    }

    int minMutation(string start, string end, vector<string>& bank)
    {
        int has = 0;
        for(auto x:bank)
        {
            if(x==end)
            {
                has = 1;
            }
        }
        if(has==0)
        {
            return -1;
        }
        int n = bank.size();
        bank.push_back(start);
        bank.push_back(end);
        vector<int> adj[n+2];
        int visited[n+2];
        int dist[n+2];
        memset(visited,0,sizeof(visited));
        memset(dist,0,sizeof(dist));
        for(int i=0;i<n+2;i++)
        {
            for(int j=i+1;j<n+2;j++)
            {
                if(mutate(bank[i],bank[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        //bfs
        queue<int> q;
        q.push(n);
        visited[n] = 1;
        dist[n] = 0;
        dist[n+1] = -1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i];
                if(!visited[v])
                {
                    visited[v] = 1;
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        return dist[n+1];
    }
};

int main()
{
    return 0;
}
