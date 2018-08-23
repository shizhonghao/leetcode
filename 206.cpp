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
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode *result = NULL,*tmp = head;
        while(head->next!=NULL)
        {
            tmp = head->next;
            head->next = result;
            result = head;
            head = tmp;
        }
        head->next = result;
        return head;
    }
};

int main()
{
    return 0;
}
