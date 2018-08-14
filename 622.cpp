#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
public:
    int q_size;
    vector<int> data;
    int l,r;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q_size = k+1;
        data.insert(data.begin(),q_size,-1);
        l = 0,r = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull())
        {
            data[r] = value;
            r++;
            r %= q_size;
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty())
        {
            l++;
            l %= q_size;
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
        {
            return -1;
        }
        return data[l];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        return data[(r-1+q_size)%q_size];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return l==r;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (r+1)%q_size==l;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */

int main()
{
    return 0;
}
