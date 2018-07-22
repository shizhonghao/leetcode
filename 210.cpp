#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<int> result;
        int indegree[numCourses];
        vector<int> adj[numCourses];
        memset(indegree,0,sizeof(indegree));
        for(int i=0;i<prerequisites.size();i++)
        {
            //u->v
            int v = prerequisites[i].first;
            int u = prerequisites[i].second;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            result.push_back(u);
            q.pop();
            for(int i=0;i<adj[u].size();i++)
            {
                int v = adj[u][i];
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        if(result.size()!=numCourses)
        {
            result.clear();
        }
        return result;
    }
};

int main()
{
    return 0;
}
