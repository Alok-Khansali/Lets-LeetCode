class MyQueue
{ // Runtime: 0 ms, faster than 100.00% of C++, Memory Usage: 7 MB, less than 86.31%
public:
    stack<int> i, o;
    /** Initialize your data structure here. */
    MyQueue()
    {
    }
    /** Push element x to the back of queue. */
    void push(int x)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        i.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if (o.empty())
            while (!i.empty())
            {
                o.push(i.top());
                i.pop();
            }
        int x = o.top();
        o.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if (o.empty())
            while (!i.empty())
            {
                o.push(i.top());
                i.pop();
            }
        return o.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return (o.empty() && i.empty());
    }
};
