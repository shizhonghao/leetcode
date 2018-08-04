#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cal(int x,char op,int y)
    {
        if(op=='+')
        {
            return x+y;
        }
        if(op=='-')
        {
            return x-y;
        }
        if(op=='*')
        {
            return x*y;
        }
    }

    vector<int> diffWaysToCompute(string input)
    {
        vector<int> result;
        int num = 0;
        for(int i=0;i<input.length();i++)
        {
            char ch = input[i];
            if(ispunct(c))
            {
                for(int a : diffWaysToCompute(input.substr(0,i)))
                {
                    for(int b : diffWaysToCompute(input.substr(i+1)))
                    {
                        result.push_back(cal(a,c,b));
                    }
                }
            }
        }
        if(result.size()==0)
        {
            result.push_back(stoi(input));
        }
        return result;
    }
};

int main()
{
    return 0;
}

