#include <bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    struct LinkList
    {
        int val;
        int key;
        LinkList *next,*prev;
        LinkList(int v,int k) : val(v), key(k), next(NULL), prev(NULL) {}
    };

    LinkList *head,*tail;
    map<int,LinkList*> has;
    int cnt;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        cnt = 0;
        head = new LinkList(-1,-1);
        tail = new LinkList(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(has.count(key)==1)
        {
            LinkList *node = has[key];
            to_top(node);
            return node->val;
        }
        return -1;
    }

    void to_top(LinkList *node)
    {
        LinkList *l = node->prev, *r = node->next;
        l->next = r;
        r->prev = l;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void put(int key, int value) {
        if(has.count(key)==1)
        {
            LinkList *node = has[key];
            node->val = value;
            to_top(node);
        }
        else
        {
            LinkList *node = new LinkList(value,key);
            has[key] = node;
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            if(cnt==cap)
            {
                LinkList *tmp = tail->prev;
                has.erase(tmp->key);
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
                delete tmp;
            }
            else
            {
                cnt++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
    return 0;
}

