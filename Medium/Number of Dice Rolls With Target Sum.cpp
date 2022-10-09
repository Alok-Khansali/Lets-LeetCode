class Solution // Runtime: 24 ms, faster than 84.00% of C++ online submissions for Number of Dice Rolls With Target Sum.
// Memory Usage: 5.9 MB, less than 99.60% of C++ online submissions for Number of Dice Rolls With Target Sum.
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        int dp[n + 1][target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        // number of dices
        for (int i = 1; i <= n; i++)
        {
            // Till the target
            for (int j = 1; j <= target; j++)
            {
                // The number of ways i can get to the target
                int count = 0;
                // Number of faces available in to the dice
                for (int f = 1; f <= k && j - f >= 0; f++)
                    count = (count + dp[i - 1][j - f]) % ((int)1e9 + 7);
                dp[i][j] = count;
            }
        }
        return dp[n][target];
    }
};