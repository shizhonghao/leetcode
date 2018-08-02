#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        bool is_prime[n+2];
        for(int i=0;i<=n;i++)
        {
            is_prime[i] = true;
        }
        is_prime[0] = is_prime[1] = false;
        for(int i=2;i<n;i++)
        {
            if(is_prime[i])
            {
                cnt++;
                for(int j=2;i*j<=n;j++)
                {
                    is_prime[i*j] = false;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}

