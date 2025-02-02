// Approach 1 : using stack
class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == ']')
            {
                if (!st.empty() && st.top() == '[')
                    st.pop();
            }
            else
                st.push(c);
        }
        return (st.size() + 1) / 2;
    }
};
// -------------Approach 2 : Improving upon the above approach-------------
// No Stack - 99.40% faster
// 91.34% better space utilisation
class Solution
{
public:
    int minSwaps(string s)
    {
        ios_base::sync_with_stdio(0);
        int open = 0;
        for (char c : s)
        {
            if (c == ']')
            {
                if (open != 0)
                    open--;
            }
            else
                open++;
        }
        return (open + 1) / 2;
    }
};