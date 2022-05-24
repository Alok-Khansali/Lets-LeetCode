// Naive 2 Pass Method, will improve it in sometime not now
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ans = 0, c = 0;
        vector<char> st;                              // Using vector as a stack
        for (int i = s.size() - 1; i >= 0; i--)       // Removing the ambiguities from the right to left
            if (s[i] == ')')
                st.push_back(')');
            else if (st.empty())
                s[i] = ')';                           // All the excess '(' are converted to ')'
            else
                st.pop_back();                        // Continuing the sequence
                
        st.clear();                                   // Clearing the stack as it might not be empty
        /*
            The above code solves the issue of excess opening brackets
            The code below works perfectly for excess closing brackets
            Hence both the excess opening and closing brackets are properly dealt with
        */
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(')                          // If opening bracket, push it
                st.push_back('(');
            else if (st.empty())                      // Now surely the bracket is a closing one
            {                                         // Stack is empty, valid sequence ends
                ans = max(ans, c);                    // Store the max of (counter , answer) in the answer variable
                c = 0;                                // Reset the counter
            }
            else                                      // If stack is not empty, the sequence continues
            {
                st.pop_back();                        // Pop the last added element
                c += 2;                               // Increase the count by 2
            }
        return max(ans, c);                           //Return the max of answer and counter, might be possible that the sequence itself
    }                                                 //Was the longest valid sequence, or maybe after some anomalies it became longest valid sequence
};

// TIME  COMPLEXITY : O(2*N) ~ O(N)
// SPACE COMPLEXITY : O(N)