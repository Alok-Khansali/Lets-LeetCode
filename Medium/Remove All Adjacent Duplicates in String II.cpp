class Solution
{ // Runtime: 15 ms, faster than 93.44% of C++ online submissions for Remove All Adjacent Duplicates in String II.
  // Memory Usage: 10.7 MB, less than 49.54% of C++ online submissions for Remove All Adjacent Duplicates in String II.
public:
    string removeDuplicates(string s, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<pair<char, int>> st;
        st.push({'#', 1});
        string ans = "";
        s += '#';
        for (int i = 0, l = 1; i < s.size() - 1; i++, l = 1)
        {
            while (s[i] == s[i + 1])
                ++i, ++l;
            if (st.top().first == s[i])
            {
                l += st.top().second;
                st.pop();
            }
            l %= k;
            if (l > 0)
                st.push({s[i], l});
        }
        while (st.size() > 1)
        {
            char c = st.top().first;
            int cc = st.top().second;
            for (int i = 0; i < cc; i++)
                ans += c;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};