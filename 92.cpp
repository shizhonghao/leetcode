#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode* l,*r = head,*tmp,*l_prev = head;
        for(int i=2;i<m;i++)
        {
            l_prev = l_prev->next;
        }
        l = l_prev->next;
        for(int i=1;i<n;i++)
        {
            r = r->next;
        }
        if(m==1)
        {
            l = head;
            head = r;
        }
        else
        {
            l_prev->next = r;
        }
        r = r->next;
        for(int i=0;i<=n-m;i++)
        {
            tmp = l->next;
            l->next = r;
            r = l;
            l = tmp;
        }
        return head;
    }
};

int main()
{

    return 0;
}
