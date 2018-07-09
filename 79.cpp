#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool find_word(vector<vector<char> >& board,vector<vector<bool> >& used,string word,int i,int j)
    {
        if(word.length()<=1)
        {
            return true;
        }
        int length = board.size();
        int height = board[0].size();
        bool found = false;
        if(i>0)
        {
            if(board[i-1][j]==word[1] && used[i-1][j]==false)
            {
                used[i-1][j] = true;
                if(find_word(board,used,word.substr(1),i-1,j))
                {
                    return true;
                }
                used[i-1][j] = false;
            }
        }
        if(i<length-1)
        {
            if(board[i+1][j]==word[1] && used[i+1][j]==false)
            {
                used[i+1][j] = true;
                if(find_word(board,used,word.substr(1),i+1,j))
                {
                    return true;
                }
                used[i+1][j] = false;
            }
        }
        if(j>0)
        {
            if(board[i][j-1]==word[1] && used[i][j-1]==false)
            {
                used[i][j-1] = true;
                if(find_word(board,used,word.substr(1),i,j-1))
                {
                    return true;
                }
                used[i][j-1] = false;
            }
        }
        if(j<height-1)
        {
            if(board[i][j+1]==word[1] && used[i][j+1]==false)
            {
                used[i][j+1] = true;
                if(find_word(board,used,word.substr(1),i,j+1))
                {
                    return true;
                }
                used[i][j+1] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char> >& board, string word)
    {
        int length = board.size();
        int height = board[0].size();
        vector<vector<bool> > used;
        vector<bool> row(height,false);
        for(int i=0;i<length;i++)
        {
            used.push_back(row);
        }
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<height;j++)
            {
                if(board[i][j]==word[0])
                {
                    used[i][j] = true;
                    if(find_word(board,used,word,i,j))
                    {
                        return true;
                    }
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
};


int main()
{
    string s = "string.";
    cout << s.substr(1) << endl;
    return 0;
}
