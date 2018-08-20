#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        if(n<=1)
        {
            return "1";
        }
        string last = countAndSay(n-1);
        string result;
        int cnt=0;
        for(int i=1;i<last.length();i++)
        {
            if(last[i]==last[i-1])
            {
                cnt++;
            }
            else
            {
                result += (cnt+1+'0');
                result += last[i-1];
                cnt = 0;
            }
        }
        result += (cnt+1+'0');
        result += last[last.length()-1];
        return result;
    }
};

int main()
{
    return 0;
}

