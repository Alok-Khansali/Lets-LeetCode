class Solution //Runtime: 4 ms, faster than 97.31% of C++ online submissions for Validate Stack Sequences.
               //Simulate the sequence to get the solution, if simulated say yes else no
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int a[1001] = {0}, l = pushed.size(), r = 0;
        stack<int> st;
        for(int i = 0; i < l;i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && popped[r] == st.top())
            {
                st.pop();
                r++;
            }
        }
        return st.empty();
    }
};