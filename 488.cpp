#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string clean(string board)
    {
        int last = 0;
        int i;
        for(i=1;i<board.length();i++)
        {
            if(board[i]!=board[i-1])
            {
                if(i-last>=3)
                {
                    return clean(board.substr(0,last) + board.substr(i));
                }
                last = i;
            }
        }
        //cout << "B:" << board << endl;
        if(i-last>=3)
        {
            return board.substr(0,last) + board.substr(i);
        }
        return board;
    }
    int len = 0;
    int result = 6;

    int findMinStep(string board, string hand)
    {

        int l = hand.length();
        len = max(len,l);
        set<char> s;
        //cout << board << endl;
        board = clean(board);
        //cout << board << endl;
        if(board.length()==0)
        {
            result = min(result,len-l);
            //cout << board << " " << hand << " " << result << endl;
        }
        if(hand.length()==0)
        {
            //return result;
        }
        for(int i=0;i<hand.length();i++)
        {
            char ch = hand[i];
            if(s.count(ch)==0)
            {
                string rest = hand;
                rest.erase(rest.begin()+i);
                s.insert(ch);
                if(board[0]==ch)
                {
                    //cout << ch+board << "-" << rest << endl;
                    int res = findMinStep(ch+board,rest);
                    //if(res!=-1) result = min(result, res+1);
                }
                for(int j=1;j<board.size();j++)
                {
                    string new_board = board;
                    string chs = "X";
                    chs[0] = ch;
                    new_board.insert(j,chs);

                    if(board[j]==ch && board[j]!=board[j-1])
                    {
                        //cout << "NB:" << board << " " <<new_board << endl;
                        //cout << new_board << "/" << rest << endl;
                        int res = findMinStep(new_board,rest);
                        //if(res!=-1) result = min(result, res+1);

                    }
                }
            }
        }
        return result==6 ? -1 : result;
    }
};

int main()
{
    return 0;
}
