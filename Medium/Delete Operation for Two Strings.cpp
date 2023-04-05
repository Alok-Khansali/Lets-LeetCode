class Solution
{ // Runtime: 18 ms, faster than 76.32% of C++ online submissions for Delete Operation for Two Strings.
public:
    int minDistance(string word1, string word2) // Basically its along the lines of lcs
    {
        int l = word1.size(), w = word2.size();
        int dp[l + 1][w + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= l; i++)
            for (int j = 1; j <= w; j++)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return l + w - 2 * dp[l][w];
    }
};