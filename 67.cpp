#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        string result;
        int lena = a.length();
        int lenb = b.length();
        int i=lena-1,j = lenb-1;
        int cnt = 0;
        int d = 0;
        while(i>=0 || j>=0)
        {
            char digit = '0'+d;
            d = 0;
            if(i>=0)
            {
                digit += a[i]-'0';
            }
            if(j>=0)
            {
                digit += b[j]-'0';
            }
            result += digit;
            if(result[cnt]>'1')
            {
                result[cnt] -= 2;
                d = 1;
            }
            i--;
            j--;
            cnt++;
        }
        if(d==1)
        {
            result.append("1");
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
    return 0;
}
