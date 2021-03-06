#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *moves(ListNode *node, int steps)
    {
        for(int i=0;i<steps;i++)
        {
            if(node==NULL)
            {
                return NULL;
            }
            node = node->next;
        }
        return node;
    }

    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        do
        {
            fast = moves(fast,2);
            slow = moves(slow,1);
            if(fast==NULL)
            {
                return false;
            }
        }
        while(slow!=fast);

        return true;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *tmp = head->next;
    tmp->next = new ListNode(3);
    tmp = tmp->next;
    tmp->next = new ListNode(4);
    tmp->next = head->next;
    Solution s;
    cout << s.hasCycle(head) << endl;
    return 0;
}


