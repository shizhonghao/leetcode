#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string result;
        int a = num1.length()-1;
        int b = num2.length()-1;
        int rem = 0;
        while(a>=0 || b>=0)
        {
            int sum = rem;
            rem = 0;
            if(a>=0)
            {
                sum += num1[a]-'0';
                a-=1;
            }
            if(b>=0)
            {
                sum += num2[b]-'0';
                b-=1;
            }
            if(sum>9)
            {
                sum -=10;
                rem = 1;
            }
            result = "0" + result;
            result[0] += sum;
        }
        if(rem==1)
        {
            result = "1" + result;
        }
        return result;
    }
};

int main()
{
    return 0;
}
