#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int tries = minutesToTest/minutesToDie + 1;
        return ceil(log(buckets)/log(tries));
    }
};

int main()
{
    return 0;
}
