#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string> > result;

    bool is_valid(vector<int> Q_pos)
    {
        for(int i=0;i<Q_pos.size();i++)
        {
            for(int j=i+1;j<Q_pos.size();j++)
            {
                if(Q_pos[i]==Q_pos[j])
                {
                    return false;
                }
                if(Q_pos[i]-i==Q_pos[j]-j)
                {
                    return false;
                }
                if(Q_pos[i]+i==Q_pos[j]+j)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void dfs(int n, vector<int> Q_pos, vector<string> board)
    {
        if(Q_pos.size()==n)
        {
            result.push_back(board);
            return;
        }
        int level = Q_pos.size();
        Q_pos.push_back(0);
        for(int i=0;i<n;i++)
        {
            Q_pos[level] = i;
            if(is_valid(Q_pos))
            {
                board[level][i] = 'Q';
                dfs(n,Q_pos,board);
                board[level][i] = '.';
            }
        }
    }

    vector<vector<string> > solveNQueens(int n)
    {
        vector<string> board;
        string dots;
        vector<int> Q_pos;
        for(int i=0;i<n;i++)
        {
            dots+='.';
        }
        for(int i=0;i<n;i++)
        {
            board.push_back(dots);
        }
        dfs(n,Q_pos,board);

        return result;
    }
};

int main()
{

    return 0;
}
