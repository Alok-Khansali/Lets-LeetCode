class Solution
{
public:
    int n;
    int dp[101][101];
    int do_it(int start, int end, string &s)
    {
        if (dp[start][end] != 0)
            return dp[start][end];
        if (start == end)
            return (dp[start][end] = 1);
        int ans = 0;
        if (s[start] == s[end] || s[end - 1] == s[end])
            ans = do_it(start, end - 1, s);
        else if (s[start] == s[start + 1])
            ans = do_it(start + 1, end, s);
        else
        {
            ans = do_it(start, end - 1, s) + 1;
            for (int i = start + 1; i < end; i++)
                if (s[i] == s[end])
                    ans = min(ans, do_it(start, i - 1, s) + do_it(i, end - 1, s));
        }
        return dp[start][end] = ans;
    }
    int strangePrinter(string s)
    {
        return do_it(0, n - 1, s);
    }
};