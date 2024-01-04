class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        ios_base::sync_with_stdio(false);            // Boosting speed 
	      cin.tie(NULL);
        if(s.size() != goal.size())
            return false;
        
        s += s;                      // if goal can be achieved then surely it would 
                                     // occur in s + s
                                     // s = eat, g = ate    s+s = eateat
                                     //                            ---
        return (s.find(goal) != string::npos);
    }
};
