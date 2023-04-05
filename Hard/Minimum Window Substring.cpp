class Solution
// Runtime: 8 ms, faster than 95.68% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 7.6 MB, less than 84.25% of C++ online submissions for Minimum Window Substring.
{
public:
    string minWindow(string s, string t)
    {
        ios_base::sync_with_stdio(0);
        if (s.size() == 0 || t.size() == 0)
            return "";
        int check[128] = {0}; // 'z' has an ascii value 127, so taking the upperlimit as 128
        int len = t.size(), mn = INT_MAX, st = 0, left = 0, i = 0;
        for (int i = 0; i < len; i++)
            check[t[i]]++;
        while (i <= s.size() && st < s.size())
            if (len)
            {
                if (i == s.size())
                    break;
                check[s[i]]--;
                if (check[s[i]] >= 0)
                    len--;
                i++;
            }
            else
            {
                if (i - st < mn)
                    mn = i - st, left = st;
                check[s[st]]++;
                if (check[s[st]] > 0)
                    len++;
                st++;
            }
        return mn == INT_MAX ? "" : s.substr(left, mn);
    }
};