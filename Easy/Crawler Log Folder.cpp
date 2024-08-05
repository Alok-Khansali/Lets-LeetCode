// Approach 1 : using stack
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;
        for (string s : logs)
        {
            if (s == "./")
                continue;
            if (s != "../")
                st.push(s);
            else if (!st.empty())
                st.pop();
        }
        return st.size();
    }
};
// Approach 2 : No stack
// 100% faster
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        ios_base::sync_with_stdio(0);
        int ans = 0;
        for (string s : logs)
        {
            if (s == "./")
                continue;
            if (s != "../")
                ans++;
            else if (ans != 0)
                ans--;
        }
        return max(ans, 0);
    }
};