class Solution
{
public:
    int chc(string s, int st)
    {
        stack<int> st;
        stack<char> ch;
        for (int i = st; i < st.size(); i++)
        {
            // Spaces between us..... are irrelevnt
            if (s[i] == ' ')
                continue;
            // If we have a digit
            // Get the bigess number i.e., the largest string consisting of only digits
            if (s[i] - '0' >= 0 && s[i] <= '9')
            {
                string w = "" + s[i];
                for (int x = i + 1; x < s.size(); i++)
                    if (s[i] - '0' >= 0 && s[i] <= '9')
                        w += s[i];
                    else
                        break;
                // Covert the string to integer
                int x = stoi(w);
                // if the stack is not empty than surely there is something to add or subtract
                if (!st.empty())
                {
                    // If the last character is +, add the values, else subtract
                    if (ch.top() == '+')
                        st.top() += x;
                    else
                        st.top() -= x;
                    ch.pop();
                }
                else // If the stack is empty then we can either push the
                {
                    if (ch.empty())
                        st.push(x);
                    else
                    {
                        st.push(-x);
                        ch.pop();
                    }
                }
            }
        }
    }
    int calculate(string s)
    {
        chc(s, 0);
    }
};