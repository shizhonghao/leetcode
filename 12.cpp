#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num)
    {
        string sym[8] = {"I","V","X","L","C","D","M"};
        string result;
        int sub = 0;
        while(num)
        {
            int x = num%5;
            string ch = sym[sub+1];
            if(num%10>4)
            {
                ch = sym[sub+2];
            }
            if(x==4)
            {
                result += ch + sym[sub];
            }
            else
            {
                while(x--)
                {
                    result += sym[sub];
                }
                if(num%10>4)
                {
                    result += sym[sub+1];
                }
            }
            sub+=2;
            num/=10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
    return 0;
}

