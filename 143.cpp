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
    void reorderList(ListNode* head)
    {
        ListNode *node = head,*tmp,*l,*r;
        int cnt = 0;
        while(node!=NULL)
        {
            node = node->next;
            cnt++;
        }
        if(cnt<2)
        {
            return ;
        }
        node = head;
        l = head;
        for(int i=1;i<(cnt+1)/2;i++)
        {
            node = node->next;
        }
        r = node->next;
        //cout <<r->val<<endl;
        node->next = NULL;
        node = r->next;
        while(node!=NULL)
        {
            tmp = node->next;
            node->next = r;
            r = node;
            node = tmp;
        }
        //cout << l->next->val << endl;
        node = head;
        l = l->next;
        for(int i=1;i<cnt;i++)
        {
            if(i%2==0)
            {
                node->next = l;
                l = l->next;
            }
            else
            {
                node->next = r;
                r = r->next;
            }
            node = node->next;
        }
        node->next = NULL;
    }
};

int main()
{
    return 0;
}
