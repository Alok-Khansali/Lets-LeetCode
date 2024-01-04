class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Palindrome.
  // Memory Usage: 6.6 MB, less than 80.81% of C++ online submissions for Longest Palindrome.
public:
    int longestPalindrome(string s)
    {
        ios_base::sync_with_stdio(0);
        int a[52] = {0}, ans = 0, mx = 0;
        for (char c : s)
            if (c >= 'a' && c <= 'z')
                a[c - 'a']++;
            else
                a[26 + c - 'A']++;
        for (int i = 0; i < 52; i++)
        {
            if (a[i] & 1)
            {
                if (a[i] >= mx)
                    ans += max(0, mx - 1), mx = a[i];
                else
                    ans += a[i] - 1;
            }
            else
                ans += a[i];
        }
        return (ans + mx);
    }
};