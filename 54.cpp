#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> result;

    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int n,m;
    vector<vector<int> > visited;

    void dfs(int i,int j,int d,int cnt,vector<vector<int> >& matrix)
    {
        if(cnt>1)
        {
            result.push_back(matrix[i][j]);
            return;
        }
        int next_i = i+dir[d][0];
        int next_j = j+dir[d][1];
        if(next_i<0 || next_i>=m || next_j<0 || next_j>=n)
        {
            dfs(i,j,(d+1)%4,cnt+1,matrix);
        }
        else
        {
            if(visited[next_i][next_j]==0)
            {
                result.push_back(matrix[i][j]);
                visited[i][j] = 1;
                dfs(next_i,next_j,d,0,matrix);
            }
            else
            {
                dfs(i,j,(d+1)%4,cnt+1,matrix);
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        if(matrix.empty())
        {
            return result;
        }
        m = matrix.size();
        n = matrix[0].size();
        vector<int> line(n,0);
        for(int i=0;i<m;i++)
        {
            visited.push_back(line);
        }
        dfs(0,0,0,0,matrix);
        return result;
    }
};


int main()
{
    return 0;
}
