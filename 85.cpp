#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int area(vector<int> &height)
    {
        stack<int> s;
        height.push_back(0);
        int maxSize = 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(s.empty() || height[i] >= height[s.top()])
            {
                s.push(i);
            }
            else
            {
                int temp = height[s.top()];
                s.pop();
                maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
                i--;
            }
        }
        return maxSize;
    }

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int result = 0;
        int n = matrix.size();
        if(n==0)
        {
            return 0;
        }
        int m = matrix[0].size();
        vector<int> h(m,0);
        memset(h,0,sizeof(h));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                {
                    h[j] = 0;
                }
                else
                {
                    h[j]++;
                }
            }

            result = max(result, area(h));

        }
        return result;
    }
};


int main()
{
    return 0;
}

