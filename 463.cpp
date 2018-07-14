#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int get_boarder(vector<vector<int> >& board,int i,int j)
    {
        int length = board.size();
        int height = board[0].size();
        int cnt = 0;
        if(i>0)
        {
            if(board[i-1][j]==1)
            {
                cnt++;
            }
        }
        if(i<length-1)
        {
            if(board[i+1][j]==1)
            {
                cnt++;
            }
        }
        if(j>0)
        {
            if(board[i][j-1]==1)
            {
                cnt++;
            }
        }
        if(j<height-1)
        {
            if(board[i][j+1]==1)
            {
                cnt++;
            }
        }

        return 4-cnt;
    }

    int islandPerimeter(vector<vector<int>>& grid)
    {
        int result = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    result += get_boarder(grid,i,j);
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
