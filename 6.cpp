#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows==1)
        {
            return s;
        }
        int len = s.length();
        string result;
        int cycle = (numRows-1)*2;
        for(int i=0;i<len/cycle+1;i++)
        {
            int sub = i*cycle;
            if(sub<len)
            {
                result += s[sub];
            }
        }
        for(int i=1;i<numRows-1;i++)
        {
            for(int j=0;j<=len/cycle+1;j++)
            {
                int sub = j*cycle;
                if(sub-i<len && sub-i>0)
                {
                    result += s[sub-i];
                }
                if(sub+i<len)
                {
                    result += s[sub+i];
                }
            }
        }
        for(int i=0;i<len/cycle+1;i++)
        {
            int sub = i*cycle+cycle/2;
            if(sub<len)
            {
                result += s[sub];
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
