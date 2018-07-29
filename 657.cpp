#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves)
    {
        int lr = 0;
        int ud = 0;
        for(int i=0;i<moves.length();i++)
        {
            if(moves[i]=='U')
            {
                ud++;
            }
            else if(moves[i]=='D')
            {
                ud--;
            }
            else if(moves[i]=='L')
            {
                lr++;
            }
            else if(moves[i]=='R')
            {
                lr--;
            }
        }
        if(lr==0 && ud==0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}

