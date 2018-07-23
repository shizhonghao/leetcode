#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    queue<pair<int,int> > q;
    vector<vector<int> > result;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    void bfs(int i,int j,vector<vector<int> >& matrix,int step)
    {
        if(result[i][j]==-1)
        {
            result[i][j]=step;
            for(int d=0;d<4;d++)
            {
                if(i+dir[d][0]>=0 && i+dir[d][0]<matrix.size() && j+dir[d][1]>=0 && j+dir[d][1]<matrix[0].size())
                {
                    q.push(make_pair(i+dir[d][0],j+dir[d][1]));
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int> >& matrix)
    {

        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return result;
        }
        vector<int> fillin(matrix[0].size(),-1);
        for(int i=0;i<matrix.size();i++)
        {
            result.push_back(fillin);
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
            }
        }
        int step = 0;
        q.push(make_pair(-1,-1));
        while(q.size()>1)
        {
            pair<int,int> p = q.front();
            q.pop();
            if(p.first==-1)
            {
                q.push(p);
                step++;
            }
            else
            {
                bfs(p.first,p.second,matrix,step);
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
