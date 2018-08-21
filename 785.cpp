#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool result = true;

    void color(vector<vector<int> >& graph, int u, vector<int> &visit)
    {
        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(!visit[v])
            {
                visit[v] = 3-visit[u];
                color(graph,v,visit);
            }
            else
            {
                if(visit[v]==visit[u])
                {
                    result = false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int> >& graph)
    {
        int n = graph.size();
        vector<int> visit(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                color(graph,i,visit);
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
