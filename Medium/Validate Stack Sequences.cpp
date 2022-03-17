class Solution //Runtime: 4 ms, faster than 97.31% of C++ online submissions for Validate Stack Sequences.
               //Simulate the sequence to get the solution, if simulated say yes else no
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> p;
        int l = pushed.size(), j = 0;
        for(int i : pushed)
        {
            p.push(i);
            while(!p.empty() && j < l && popped[j] == p.top() )
            {
                p.pop();
                j++;
            }
        }
        return p.empty();
    }
};