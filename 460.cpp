#include <bits/stdc++.h>

using namespace std;


class LFUCache {
public:
    struct LinkList
    {
        int val;
        int key;
        int freq;
        LinkList *next,*prev;
        LinkList(int v,int k) : val(v), key(k), freq(1), next(NULL), prev(NULL) {}
    };

    struct FreqList
    {
        int freq;
        LinkList *head,*tail;
        FreqList(int f) : freq(f)
        {
            head = new LinkList(-1,-1);
            tail = new LinkList(-1,-1);
            head->next = tail;
            tail->prev = head;
        }
    };

    int cap;
    int cnt;
    map<int,FreqList*> freq_has;
    map<int,LinkList*> has;

    LFUCache(int capacity)
    {
        cap = capacity;
        cnt = 0;
    }

    int get(int key) {
        if(cap==0)
        {
            return -1;
        }
        if(has.count(key)==1)
        {
            LinkList *node = has[key];
            add_freq(node);
            return node->val;
        }
        return -1;
    }

    void add_freq(LinkList *node)
    {
        LinkList *l = node->prev, *r = node->next;
        l->next = r;
        r->prev = l;
        node->freq += 1;
        int freq = node->freq;
        if(freq_has.count(freq)==0)
        {
            freq_has[freq] = new FreqList(freq);
        }
        LinkList *head = freq_has[freq]->head, *tail = freq_has[freq]->tail;

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

    }

    void rm_last()
    {
        map<int,FreqList*> ::iterator it;
        for(it=freq_has.begin();it!=freq_has.end();it++)
        {
            FreqList* f = it->second;
            if(f->head->next!=f->tail)
            {
                LinkList *tmp = f->tail->prev;
                has.erase(tmp->key);
                f->tail->prev->prev->next = f->tail;
                f->tail->prev = f->tail->prev->prev;
                delete tmp;
                break;
            }
        }
    }

    void put(int key, int value)
    {
        if(has.count(key)==1)
        {
            LinkList *node = has[key];
            node->val = value;
            add_freq(node);
        }
        else
        {
            if(cnt==cap)
            {
                rm_last();
            }
            else
            {
                cnt++;
            }
            LinkList *node = new LinkList(value,key);
            has[key] = node;
            if(freq_has.count(1)==0)
            {
                freq_has[1] = new FreqList(1);
            }
            LinkList *head = freq_has[1]->head;
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
    return 0;
}
