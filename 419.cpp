/*
space O(1),
time O(n^2)
mark 2 for 1*1 battleships(0 directions connected)
mark 1 for endings of 1*n battleships(1 directions connected)
mark 0 for the middle part of 1*n battleships(2 directions connected)
result = mark/2;
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int adj_mark(vector<vector<char>>& board,int i,int j)
    {
        int length = board.size();
        int height = board[0].size();
        int cnt = 0;
        if(i>0)
        {
            if(board[i-1][j]=='X')
            {
                cnt++;
            }
        }
        if(i<length-1)
        {
            if(board[i+1][j]=='X')
            {
                cnt++;
            }
        }
        if(j>0)
        {
            if(board[i][j-1]=='X')
            {
                cnt++;
            }
        }
        if(j<height-1)
        {
            if(board[i][j+1]=='X')
            {
                cnt++;
            }
        }

        if(cnt==0)
        {
            return 2;
        }
        if(cnt==1)
        {
            return 1;
        }
        if(cnt==2)
        {
            return 0;
        }
    }

    int countBattleships(vector<vector<char>>& board)
    {
        int length = board.size();
        int height = board[0].size();
        int result, mark = 0;
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<height;j++)
            {
                if(board[i][j]=='X')
                {
                    mark += adj_mark(board,i,j);
                }
            }
        }

        result = mark/2;
        return result;
    }
};

int main()
{
    int m,n;
    cin >> m >> n;
    for()
    return 0;
}
