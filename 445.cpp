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
    int list_size(ListNode* head)
    {
        if(head->next == NULL)
        {
            return 1;
        }
        return list_size(head->next) + 1;
    }

    ListNode* add(ListNode* l1,ListNode* l2,int len, int wait)
    {
        ListNode* node;
        if(len>0)
        {
            if(wait>0)
            {
                node = new ListNode(l1->val);
                node->next = add(l1->next,l2,len-1,wait-1);
            }
            else
            {
                node = new ListNode(l1->val+l2->val);
                node->next = add(l1->next,l2->next,len-1,0);
            }
            if(node->next->val>9)
            {
                node->next->val -= 10;
                node->val++;
            }
        }
        else
        {
            node = new ListNode(l1->val+l2->val);
            node->next = NULL;
        }
        return node;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int len1 = list_size(l1);
        int len2 = list_size(l2);
        if(len2>len1)
        {
            swap(len1,len2);
            swap(l1,l2);
        }
        ListNode* head = add(l1,l2,len1-1,len1-len2);

        if(head->val>9)
        {cout<<"here"<<endl;
            ListNode* tmp = new ListNode(1);
            head->val -= 10;
            tmp->next = head;
            head = tmp;
        }
        cout<<"there"<<endl;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode* l1, *l2;
    l1 = new ListNode(5);
    l2 = new ListNode(5);
    cout << s.addTwoNumbers(l1,l2)->val << endl;
    return 0;
}
