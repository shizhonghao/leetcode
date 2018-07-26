#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<char,int> val;

    int romanToInt(string s)
    {
        int result = 0;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        for(int i=0;i<s.length()-1;i++)
        {
            if(val[s[i]]>=val[s[i+1]])
            {
                result += val[s[i]];
            }
            else
            {
                result -= val[s[i]];
            }
        }
        result += val[s[s.length()-1]];
        return result;
    }
};

int main()
{
    return 0;
}

