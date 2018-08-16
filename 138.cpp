#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode *new_head = new RandomListNode(0);
        RandomListNode *tmp = new_head;
        RandomListNode *node = head;
        while(node!=NULL)
        {
            tmp->next = new RandomListNode(node->label);
            tmp = tmp->next;
            m[node] = tmp;
            node = node->next;
        }

        node = head;
        tmp = new_head->next;
        while(node!=NULL)
        {
            tmp->random = m[node->random];
            tmp = tmp->next;
            node = node->next;
        }

        return new_head->next;
    }
};

int main()
{
    return 0;
}
