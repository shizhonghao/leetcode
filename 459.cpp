#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int len = s.length();
        string add = (s+s).substr(1,len*2-2);
        return add.find(s)!=-1;
    }
};

int main()
{
    return 0;
}
