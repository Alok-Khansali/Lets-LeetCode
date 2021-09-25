class MinStack {  //this is an O(1) time and O(1) Space solution
  //Another approach could be to use two stack one original and one for storing minimum values
public:
    stack<long> m;
    long mn;
    MinStack() {    }    
    void push(long val) 
    {
        ios_base::sync_with_stdio(false);
        if(m.empty())
            m.push(val), mn=val;
        else if(val >= mn)
          m.push(val);
        else 
           m.push(2*val - mn), mn = val; 
    }
    void pop() 
    {
        ios_base::sync_with_stdio(false);
        if(m.top() < mn)
          mn = 2*mn - m.top();
        m.pop();
    }
    int top() 
    {  
        ios_base::sync_with_stdio(false);
        return((m.top() > mn) ? m.top() : mn);
    }
    int getMin() 
    {
        ios_base::sync_with_stdio(false);
        return mn;
    }
};
