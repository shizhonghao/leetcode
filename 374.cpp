#include <bits/stdc++.h>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n)
    {
        unsigned int l = 0,r = n;
        unsigned int mid = (l+r)/2;
        int res = guess(mid);
        while(res!=0)
        {
            if(res==1)
            {
                l = mid+1;
            }
            else if(res==-1)
            {
                r = mid;
            }
            mid = (l+r)/2;
            res = guess(mid);
        }
        return mid;
    }
};

int main()
{
    return 0;
}
