#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    int findNthDigit(int n)
    {
        int digits = 1;
        int min_val = 1;
        int interval_len = 9;
        long long len_sum = 9;
        int x = n;
        while(n>len_sum)
        {
            x = n - len_sum;
            interval_len *= 10;
            min_val *= 10;
            digits++;
            len_sum += (long long)digits*interval_len;
            //cout << len_sum << ' ';
        }
        int num = min_val + (x-1)/digits;
        stringstream s;
        s << num;
        string str = s.str();
        //cout << x << " " << min_val << " " << num << " " << (x-1)%digits;
        return str[(x-1)%digits]-'0';

    }
};

int main()
{
    return 0;
}



