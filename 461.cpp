#include <bits/stdc++>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int result = 0;
        while(x || y)
        {
            result += (x&1)^(y&1);
            x>>=1;
            y>>=1;
        }
        return result;
    }
};

int main()
{
    return 0;
}
