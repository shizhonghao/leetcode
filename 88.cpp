#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i=m-1,j=n-1;
        for(int sub=m+n-1;sub>=0;sub--)
        {
            if(i<0)
            {
                nums1[sub] = nums2[j];
                j--;
            }
            if(j<0 || nums1[i]>nums2[j])
            {
                nums1[sub] = nums1[i];
                i--;
            }
            else
            {
                nums1[sub] = nums2[j];
                j--;
            }
        }
    }
};

int main()
{
    return 0;
}
