#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stk;
    map<int,int> cnt;

    MinStack()
    {
        stk.clear();
        cnt.clear();
    }

    void push(int x)
    {
        stk.push_back(x);
        cnt[x]++;
    }

    void pop()
    {
        int last = stk.back();
        stk.pop_back();
        if(cnt[last]==1)
        {
            cnt.erase(last);
            return;
        }
        cnt[last]--;
    }

    int top()
    {
        return stk.back();
    }

    int getMin()
    {
        return cnt.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
    MinStack *obj = new MinStack();
    obj->push(5);
    obj->push(4);
    obj->push(5);
    obj->push(1);
    obj->push(2);
    obj->push(0);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_3 << " " << param_4 << endl;
    return 0;
}
