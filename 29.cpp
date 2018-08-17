#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long div(long long a,long long b)
    {
        long long result=0;
        long long x=1;
        while(a>=b)
        {
            x<<=1;
            b<<=1;
        }
        while(a && b)
        {
            //cout <<a << ' ' << b<<" "<<result<<endl;
            if(a>=b)
            {
                a-=b;
                result += x;
            }
            b>>=1;
            x>>=1;
        }
        return result;
    }

    int divide(int dividend, int divisor)
    {
        int r = 0x7fffffff;
        int l = 0x80000000;
        if(dividend==0)
        {
            return 0;
        }
        if(divisor==0)
        {
            return r;
        }
        bool op = (dividend<0);
        op ^= (divisor<0);
        long long result = div(abs((long long)dividend),abs((long long)divisor));
        //cout<<result<<endl;
        if(op)
        {
            result = -result;
        }
        if(result<l || result>r)
        {
            return r;
        }
        return result;
    }
};
int main()
{
    Solution s;
    cout << s.divide(7,3) << endl;
    return 0;
}
