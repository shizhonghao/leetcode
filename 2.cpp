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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head, *node=NULL;
        int rem = 0;
        int cnt=0;
        while(l1!=NULL || l2!=NULL)
        {
            int sum = rem;
            rem = 0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2 = l2->next;
            }
            if(sum>9)
            {
                sum -=10;
                rem = 1;
            }
            if(cnt==0)
            {
                head = new ListNode(sum);
                node = head;
            }
            else
            {
                node->next = new ListNode(sum);
                node = node->next;
            }
            cnt++;
        }
        if(rem==1)
        {
            node->next = new ListNode(1);
        }
        return head;
    }
};

int main()
{
    return 0;
}
