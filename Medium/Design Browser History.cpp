// Stack based Solution
class BrowserHistory {
public:
    stack<string> curr, fwd;
    BrowserHistory(string homepage) 
    {
        curr.push(homepage);
    }
    
    void visit(string url) 
    {
        while(!fwd.empty())
        fwd.pop();
        curr.push(url);
    }
    
    string back(int steps) 
    {
        string x;
        while(steps--  && curr.size() > 1)
        {
            x = curr.top();
            fwd.push(x);
            curr.pop();
        }
        return curr.top();
    }
    
    string forward(int steps) 
    {
        string x;
        while(steps--  && !fwd.empty())
        {
            x = fwd.top();
            curr.push(x);
            fwd.pop();
        }
        return curr.top();
    }
};
// Linked List Solution