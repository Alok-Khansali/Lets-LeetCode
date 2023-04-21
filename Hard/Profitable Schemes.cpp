class Solution
{
public:
    long long dp[101][101][101], mod = 1e9 + 7;
    int ans(vector<int> &g, vector<int> &p, int index, int working, int profit, int men, int mP)
    {
        if (index >= g.size())
            return mP <= profit;
        if (dp[index][working][profit] != -1)
            return dp[index][working][profit];
        dp[index][working][profit] = ans(g, p, index + 1, working, profit, men, mP);
        if (working + g[index] <= men)
            dp[index][working][profit] += ans(g, p, index + 1, working + g[index], min(mP, profit + p[index]), men, mP);
        dp[index][working][profit] %= mod;
        return dp[index][working][profit];
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(dp, -1, sizeof(dp));
        return ans(group, profit, 0, 0, 0, n, minProfit);
    }
};