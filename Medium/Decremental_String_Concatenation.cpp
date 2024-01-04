class Solution
{
public:
    vector<vector<int>> dp;
    int DP(vector<string> &w, int i, int n, string s, int p)
    {
        if (i == n)
            return (dp[i][p] = 0);
        if (dp[i][p] != -1)
            return dp[i][p];
        int x = s.size();
        if (p == 0)
        {
            int l = w[i].size() - 1;
            if (w[i][l] == s[0])
                s = w[i].substr(0, l) + s;
            else
                s = w[i] + s;
        }
        else
        {
            int l = w[i].size() - 1;
            if (w[i][0] == s[x - 1])
                s += w[i].substr(1);
            else
                s += w[i];
        }
        dp[i][p] = s.size() + min(DP(w, i + 1, n, s, 0), DP(w, i + 1, n, s, 1));
        cout << s << ' ';
        return dp[i][p];
    }
    int minimizeConcatenatedLength(vector<string> &words)
    {
        int l = words.size();
        dp.resize(l + 1, vector<int>(2, -1));
        int ans = min(DP(words, 1, l, words[0], 0), DP(words, 1, l, words[0], 1));
        return ans;
    }
};