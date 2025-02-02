// Approach 1 : using Stack
class Solution
{
public:
    int minLength(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (!st.empty() && c == 'B')
            {
                if (st.top() == 'A')
                    st.pop();
                else
                    st.push('B');
            }
            else if (!st.empty() && c == 'D')
            {
                if (st.top() == 'C')
                    st.pop();
                else
                    st.push('D');
            }
            else
                st.push(c);
        }
        return st.size();
    }
};
// Approach 2 : no extra Space
class Solution
{
public:
    int minLength(string s)
    {
        char prev = s[0];
        int ind = 0, len = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == 'B')
            {
                if (prev == 'A')
                {
                    len--;
                    ind--;
                    if (ind > 0)
                        prev = s[ind];
                    continue;
                }
            }
            else if (s[i] == 'D')
            {
                if (prev == 'C')
                {
                    len--;
                    ind--;
                    if (ind > 0)
                        prev = s[ind];
                    continue;
                }
            }
            len++;
            ind = i;
            prev = s[i];
        }
        return len;
    }
};