#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        if(height.size()==0)
        {
            return 0;
        }
        int result = 0;
        int l = 0;
        int r = height.size()-1;
        int l_height = height[l],r_height = height[r];
        while(l<r)
        {
            if(l_height<r_height)
            {
                l_height = max(l_height,height[l]);
                result+=max(0,l_height-height[l]);
                l++;
            }
            else
            {
                r_height = max(r_height,height[r]);
                result+=max(0,r_height-height[r]);
                r--;
            }
        }
        return result;
    }

};

int main()
{

    return 0;
}
