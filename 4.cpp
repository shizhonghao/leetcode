#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int l1,l2,r1,r2;

    int get_min(vector<int>& nums1,vector<int>& nums2)
    {
        if(l1==r1+1)
        {
            return nums2[l2++];
        }
        if(l2==r2+1)
        {
            return nums1[l1++];
        }
        if(nums1[l1]<nums2[l2])
        {
            return nums1[l1++];
        }
        else
        {
            return nums2[l2++];
        }
    }

    int get_max(vector<int>& nums1,vector<int>& nums2)
    {
        if(l1==r1+1)
        {
            return nums2[r2--];
        }
        if(l2==r2+1)
        {
            return nums1[r1--];
        }
        if(nums1[r1]>nums2[r2])
        {
            return nums1[r1--];
        }
        else
        {
            return nums2[r2--];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        double result;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1+len2;
        double divisor;
        int sum = 0;
        for(int i=0;i<len1;i++)
        {
            sum += nums1[i];
        }
        for(int i=0;i<len2;i++)
        {
            sum += nums2[i];
        }
        if(len%2==0)
        {
            len -= 2;
            divisor = 2.0;
        }
        else
        {
            len -= 1;
            divisor = 1.0;
        }

        l1 = l2 = 0;
        r1 = len1-1;
        r2 = len2-1;
        for(int i=0;i<len/2;i++)
        {
            sum -= get_min(nums1,nums2);
            //cout << sum << endl;
            sum -= get_max(nums1,nums2);
            //cout << sum << endl;
        }

        result = sum/divisor;
        return result;
    }
};


int main()
{

    return 0;
}
