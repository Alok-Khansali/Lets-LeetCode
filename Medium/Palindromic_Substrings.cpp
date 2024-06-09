class Solution // Runtime: 3 ms, faster than 91.94% of C++ online submissions for Palindromic Substrings.
               // Memory Usage: 6.3 MB, less than 82.67% of C++ online submissions for Palindromic Substrings.
{
public:
    int countSubstrings(string s) // Two Pointer
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int len = s.size(), ans = 0;
        for (int i = 0; i < len; i++)
        {
            int l = i - 1, r = i + 1;                 // left and rights of an index
            ans++;                                    // Single char is always a palindrome
            while (l >= 0 && r < len && s[l] == s[r]) // Checking Around (Odd base)
                ans++, l--, r++;
            l = i, r = i + 1;
            while (l >= 0 && r < len && s[l] == s[r]) // Checking adjacent(even base)
                ans++, l--, r++;
        }
        return ans;
    }
};


// TC = O(N^3)
// Naive Solution 80ms solution, still works
class Solution
{
public:
    int check(string &s, int st, int en) // O(N/2)
    {
        int l = s.size();
        while (st < en)
            if (s[st] != s[en])
                return 0;
            else
                st++, en--;
        return 1;
    }
    int countSubstrings(string s)
    {
        int l = s.size(), ans = l;
        for (int i = l - 1; i >= 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (s[i] == s[j])
                    ans += check(s, j, i);
            }
        }
        return ans;
    }
};