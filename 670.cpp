#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSwap(int num)
    {
        string digits = to_string(num);
        int sub = 0,dig = 0;
        for(int i=0;i<digits.length();i++)
        {
            for(int j=i+1;j<digits.length();j++)
            {
                if(digits[j]>digits[i] && digits[j]>=dig)
                {
                    dig = digits[j];
                    sub = j;
                }
            }
            if(sub!=0)
            {
                swap(digits[i],digits[sub]);
                break;
            }
        }
        return stoi(digits);
    }
};

int main()
{
    return 0;
}
