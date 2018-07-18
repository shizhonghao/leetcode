#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const double PI = acos(-1.0);

    struct complex
    {
        double r,i;
        complex(double _r = 0.0,double _i = 0.0)
        {
            r = _r; i = _i;
        }
        complex operator +(const complex &b)
        {
            return complex(r+b.r,i+b.i);
        }
        complex operator -(const complex &b)
        {
            return complex(r-b.r,i-b.i);
        }
        complex operator *(const complex &b)
        {
            return complex(r*b.r-i*b.i,r*b.i+i*b.r);
        }
    };

    void change(complex y[],int len)
    {
        int i,j,k;
        for(i = 1, j = len/2;i < len-1; i++)
        {
            if(i < j)
            {
                swap(y[i],y[j]);
            }
            k = len/2;
            while( j >= k)
            {
                j -= k;
                k /= 2;
            }
            if(j < k)
            {
                j += k;
            }
        }
    }

    void fft(complex y[],int len,int on)
    {
        change(y,len);
        for(int h = 2; h <= len; h <<= 1)
        {
            complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
            for(int j = 0;j < len;j+=h)
            {
                complex w(1,0);
                for(int k = j;k < j+h/2;k++)
                {
                    complex u = y[k];
                    complex t = w*y[k+h/2];
                    y[k] = u+t;
                    y[k+h/2] = u-t;
                    w = w*wn;
                }
            }
        }
        if(on == -1)
        {
            for(int i = 0;i < len;i++)
            {
                y[i].r /= len;
            }
        }
    }

    string mult(string num1,string num2)
    {
        string result;
        int len = num1.length()+num2.length();
        int res[len+1];
        memset(res,0,sizeof(res));
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.length();i++)
        {
            for(int j=0;j<num2.length();j++)
            {
                res[i+j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=0;i<len;i++)
        {
            res[i+1] += res[i]/10;
            res[i] %= 10;
        }
        while(res[len]==0 && len>0)
        {
            len--;
        }
        for(int i=len;i>=0;i--)
        {
            result += res[i]+'0';
        }
        return result;
    }

    string multiply(string num1, string num2)
    {
        string result;
        int len1 = num1.length();
        int len2 = num2.length();
        int len = 1;
        while(len<len1*2 || len<len2*2)
        {
            len <<= 1;
        }
        complex x1[len],x2[len];
        int sum[len];

        for(int i=0;i<len1;i++)
        {
            x1[i] = complex(num1[len1-1-i]-'0',0);
        }
        for(int i=len1;i<len;i++)
        {
            x1[i] = complex(0,0);
        }
        for(int i=0;i<len2;i++)
        {
            x2[i] = complex(num2[len2-1-i]-'0',0);
        }
        for(int i=len2;i<len;i++)
        {
            x2[i] = complex(0,0);
        }

        fft(x1,len,1);
        fft(x2,len,1);
        for(int i=0;i<len;i++)
        {
            x1[i] = x1[i]*x2[i];
        }
        fft(x1,len,-1);

        for(int i=0;i<len;i++)
        {
            sum[i] = (int)(x1[i].r+0.5);
        }
        for(int i=0;i<len;i++)
        {
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
        len = len1+len2-1;
        while(sum[len]<=0 && len>0)
        {
            len--;
        }
        for(int i=len;i>=0;i--)
        {
            result += sum[i]+'0';
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("2","3") << endl;
    return 0;
}
