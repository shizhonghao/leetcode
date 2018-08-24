#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s)
    {
        if(regex_match(s,regex("^ *[+-]?(([0-9]+[.]?[0-9]*)|[.][0-9]+)(e[+-]?[0-9]+)? *$")))
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
