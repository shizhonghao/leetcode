#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    stack<int> q1;
    stack<int> q2;
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        q1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if(q2.empty())
        {
            while(!q1.empty())
            {
                int x = q1.top();
                q2.push(x);
                q1.pop();
            }
        }
        int x = q2.top();
        q2.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        if(q2.empty())
        {
            while(!q1.empty())
            {
                int x = q1.top();
                q2.push(x);
                q1.pop();
            }
        }
        return q2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main()
{

    return 0;
}
