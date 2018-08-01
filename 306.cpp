#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sum(string a, string b)
    {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string c;
        int len = max(a.length(),b.length());
        for(int i=0;i<len;i++)
        {
            c.append("0");
            if(i<a.length())
            {
                c[i]+=a[i]-'0';
            }
            if(i<b.length())
            {
                c[i]+=b[i]-'0';
            }
        }
        for(int i=1;i<len;i++)
        {
            if(c[i-1]>'9')
            {
                c[i-1]-=10;
                c[i]++;
            }
        }
        if(c[len-1]>'9')
        {
            c[len-1]-=10;
            c.append("1");
        }
        reverse(c.begin(),c.end());
        return c;
    }

    bool is_valid(string num, string l1, string l2 )
    {
        //cout << num << " " << l1 << " " << l2 << endl;
        string s = sum(l1,l2);
        if((l1[0]=='0' && l1.length()>1) || (l2[0]=='0' && l2.length()>1) )
        {
            return false;
        }
        if(s==num.substr(0,s.length()))
        {
            if(num.length()==s.length())
            {
                return true;
            }
            else if(num.length()>s.length())
            {
                return is_valid(num.substr(s.length()),l2,s);
            }
        }


        return false;
    }

    bool isAdditiveNumber(string num)
    {
        int n = num.length();
        for(int i=1;i<=n/2;i++)
        {
            for(int j=1;max(i,j)<=n-i-j;j++)
            {
                if(is_valid(num.substr(i+j), num.substr(0,i),num.substr(i,j) ))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}

