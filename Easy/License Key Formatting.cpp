class Solution // Could have done in a single pass as well, maybe next time
{              // Runtime: 29 ms, faster than 23.75% of C++ online submissions for License Key Formatting.
               // Memory Usage: 9.2 MB, less than 5.77% of C++ online submissions for License Key Formatting.
public:
    string licenseKeyFormatting(string s, int k)
    {
        string ans = "", w = "";
        for (char c : s)
            if (c != '-')
                if (c >= 'a' && c <= 'z')
                    w += (char)('A' + (c - 'a'));
                else
                    w += c;
        int l = w.size(), x = l % k;
        if (x == 0)
        {
            ans = w.substr(0, k);
            x = k;
        }
        else
            ans = w.substr(0, x);
        for (int i = x; i < l; i += k)
            ans += '-' + w.substr(i, k);
        return ans;
    }
};