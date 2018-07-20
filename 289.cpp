#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dir[8][2] = {{0,1},{1,1},{1,0},{-1,1},{0,-1},{-1,-1},{-1,0},{1,-1} };
    int n,m;

    int cnt_cells(int i,int j,vector<vector<int> >& board)
    {
        int cnt = 0;
        for(int d=0;d<8;d++)
        {
            int i_next = i+dir[d][0];
            int j_next = j+dir[d][1];
            if(i_next<0 || i_next>=m || j_next<0 || j_next>=n)
            {
                continue;
            }
            if(board[i_next][j_next]>=1)
            {
                cnt++;
            }
        }
        return cnt;
    }

    void gameOfLife(vector<vector<int> >& board)
    {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==0)
                {
                    board[i][j] -= cnt_cells(i,j,board);
                }
                else
                {
                    board[i][j] += cnt_cells(i,j,board);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==-3 || board[i][j]==3 || board[i][j]==4)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    return 0;
}

