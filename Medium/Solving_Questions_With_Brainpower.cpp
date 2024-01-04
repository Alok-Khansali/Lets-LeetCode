class Solution
{
public:
    long long dp[2006][2006];
    long long dp2(vector<vector<int>> &q, int i, int j, int l)
    {
        if (j >= l)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        else
            dp[i][j] = max(dp2(q, i, j + 1, l), q[j][0] + dp2(q, i, i + q[j][1] + 1, l));
        return dp[i][j];
    }
    long long mostPoints(vector<vector<int>> &q)
    {
        memset(dp, -1, sizeof(dp));
        long long ans = 0, r = q.size();
        for (int i = 0; i < r; i++)
            ans = max(ans, dp2(q, i, i, r));
        return ans;
    }
};