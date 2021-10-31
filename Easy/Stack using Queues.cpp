class MyStack {                                 //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Stack using Queues.
public:
    deque<int> dq;                              //A deque with front addition behaves like a stack
    MyStack() {
        
    }
    void push(int x) 
    {
        ios_base::sync_with_stdio(false);
        dq.push_front(x);                       //Elements will be added at the front like a stack
    }
    
    int pop() 
    {
        ios_base::sync_with_stdio(false);
        int x = dq.front();
        dq.pop_front();
        return x;
    }
    
    int top() 
    {
        return dq.front();
    }
    
    bool empty() 
    {
        return (dq.empty());
    }
};
/*  //Queue Implementation

/*