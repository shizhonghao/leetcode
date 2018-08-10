#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calc(int x,int y,string op)
    {
        if(op=="+")
        {
            return x+y;
        }
        else if(op=="-")
        {
            return x-y;
        }
        else if(op=="*")
        {
            return x*y;
        }
        else if(op=="/")
        {
            return x/y;
        }
    }

    int evalRPN(vector<string>& tokens)
    {
        stack<int> nums;
        for(int i=0;i<tokens.size();i++)
        {
            string op = tokens[i];
            if( (op[0]<='9' && op[0]>='0')||op.length()>1 )
            {
                int num = stoi(tokens[i]);
                nums.push(num);
            }
            else
            {
                int y = nums.top();
                nums.pop();
                int x = nums.top();
                nums.pop();
                int res = calc(x,y,op);
                nums.push(res);
            }
        }
        return nums.top();
    }
};

int main()
{
    return 0;
}
