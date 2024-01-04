class Solution {  //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Baseball Game.
                  //Memory Usage: 8.3 MB, less than 95.60% of C++ online submissions for Baseball Game.
public:
    int calPoints(vector<string>& ops) 
    {
        int ans = 0;
        stack<int> st;
        for(string s: ops)
        {
            if(s == "C")
                st.pop();
            else if(s == "D")
                st.push(st.top()*2);
            else if(s == "+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                y += x;
                st.push(x);
                st.push(y);
            }
            else
                st.push(stoi(s));
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};