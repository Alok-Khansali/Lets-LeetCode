class FreqStack // Runtime: 148 ms, faster than 99.92% of C++ online submissions for Maximum Frequency Stack.
                // Memory Usage: 86.4 MB, less than 63.11% of C++ online submissions for Maximum Frequency Stack.
{
public:
    unordered_map<int,stack<int>> mp;    
    unordered_map<int,int> f; 
    int i;                               //freq var
    FreqStack() 
    {
        i = 0;
    }
    void push(int val) 
    {
        ios_base::sync_with_stdio(0);
	    cin.tie(NULL);
        f[val]++;
        i = max(i,f[val]);
        mp[f[val]].push(val);
    }
    int pop() 
    {
        ios_base::sync_with_stdio(0);
	    cin.tie(NULL);  
        int t = mp[i].top();
        f[t]--;
        mp[i].pop();
        i -= (mp[i].empty());
        return t;
    }
};