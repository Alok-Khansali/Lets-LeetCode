class Solution // Runtime: 31 ms, faster than 79.04% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 16.3 MB, less than 37.71% of C++ online submissions for Repeated Substring Pattern.
{
public:
    bool repeatedSubstringPattern(string s)
    {
        ios_base::sync_with_stdio(0);
        string w = "";
        int l = 0, c = 0, x = s.size();
        for (int i = 0; i < x / 2; i++)
        {
            w += s[i];
            l = w.size(), c = 1;
            if (x % l != 0)
                continue;
            for (int j = 0; j <= x - l; j += l)
                if (s.substr(j, l) != w)
                {
                    c = 0;
                    break;
                }
            if (c)
                return true;
        }
        return 0;
    }
};

//Approach 2 : KMP
//Approach 3 : One liner