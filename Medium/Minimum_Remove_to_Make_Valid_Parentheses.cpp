class Solution
{ // Runtime: 15 ms, faster than 98.27% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
  // Memory Usage: 11 MB, less than 66.20% of C++ online submissions for Minimum
public:
    string minRemoveToMakeValid(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // Initialize variables
        string ans = "";
        int openBrackets = 0, closeBrackets = 0, openCount = 0, closeCount = 0;
        // Count the number of open and close brackets
        for (char c : s)
            if (c == '(')
                ++openBrackets;
            else if (c == ')' && openBrackets > closeBrackets)
                ++closeBrackets;
        // Iterate through the string again to build the resulting string
        for (char c : s)
        {
            if (c == '(')
            {
                // If the current character is an open bracket, increment openCount
                int temp = openCount + 1;
                if (temp <= closeBrackets)
                    // If openCount is less than or equal to closeBrackets, append the character to the answer
                    ans += c, openCount++;
            }
            else if (c == ')')
            {
                // If the current character is a close bracket, increment closeCount
                int temp = closeCount + 1;
                if (temp <= openCount)
                    // If closeCount is less than or equal to openCount, append the character to the answer
                    ans += c, closeCount++;
            }
            else
                // If the current character is not a bracket, append it to the answer
                ans += c;
        }
        // Return the resulting string
        return ans;
    }
};
// Approach 2 : Using the Stack with useless bruteforce
// Just for brain Exercise
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.empty())
                    s[i] = '-';
                else
                    st.pop();
            }
        }
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            s = s.substr(0, x) + s.substr(x + 1);
        }
        int i = s.size() - 1;
        while (i >= 0)
        {
            if (s[i] == '-')
                s = s.substr(0, i) + s.substr(i + 1);
            i--;
        }
        return s;
    }
};

// Approach 3 : Stack - with its good use
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        vector<bool> remove(s.size(), false); // Store whether each character needs to be removed
        // First pass: mark characters to be removed
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.empty())
                    remove[i] = true; // Mark this ')' for removal
                else
                    st.pop();
            }
        }
        // Mark remaining unmatched '(' for removal
        while (!st.empty())
        {
            remove[st.top()] = true;
            st.pop();
        }
        // Construct the final string with marked characters removed
        string result = "";
        for (int i = 0; i < s.size(); i++)
            if (!remove[i])
                result += s[i];
        return result;
    }
};