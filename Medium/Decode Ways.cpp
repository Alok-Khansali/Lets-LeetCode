class Solution // TLE
{
public:
    int l;
    int recur(string s, int st, int inc)
    {
        if (s[st] == '0' || st + inc > l)
            return 0;
        int cur = stoi(s.substr(st, inc));
        if (cur > 26)
            return 0;
        if (st + inc == l)
            return 1;
        int x = 0;
        if (inc == 2)
            x = recur(s, st + 2, 1) + recur(s, st + 2, 2);
        else
            x = recur(s, st + 1, 1) + recur(s, st + 1, 2);
        return x;
    }
    int numDecodings(string s)
    {
        l = s.size();
        return recur(s, 0, 1) + recur(s, 0, 2);
    }
};

// 1 D dp, to do memoisation
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> mem(n + 1, -1);
        mem[n] = 1;
        return s.empty() ? 0 : num(0, s, mem);
    }
    int num(int i, string &s, vector<int> &mem)
    {
        if (mem[i] > -1)
            return mem[i];
        if (s[i] == '0')
            return mem[i] = 0;
        int res = num(i + 1, s, mem);
        if (i < s.size() - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
            res += num(i + 2, s, mem);
        return mem[i] = res;
    }
};

// Best finally
class Solution
{
public:
    int numDecodings(string s)
    {
        int p = 1, pp, n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int cur = s[i] == '0' ? 0 : p;
            if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
                cur += pp;
            pp = p;
            p = cur;
        }
        return s.empty() ? 0 : p;
    }
};

// The one i wrote
class Solution // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 6.1 MB, less than 93.04% of C++ online submissions for Decode Ways.
{
public:
    int numDecodings(string s)
    {
        ios_base::sync_with_stdio(0);
        int n = s.size(), dp[n + 1];
        dp[n] = 1;
        dp[n - 1] = (s[n - 1] == '0') ? 0 : 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] == '0')
                dp[i] = 0;
            else
            {
                dp[i] = dp[i + 1];
                int x = stoi(s.substr(i, 2));
                if (x < 27)
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};