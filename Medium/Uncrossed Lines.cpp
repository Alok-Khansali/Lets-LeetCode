class Solution // 19 ms Recursive solution
{
public:
    int v[501][501];
    int dp(int i, int j, int n, int m, vector<int> &a, vector<int> &b)
    {
        if (i == n || j == m)
        {
            v[i][j] = 0;
            return 0;
        }
        if (v[i][j] != -1)
            return v[i][j];
        if (a[i] == b[j])
            v[i][j] = 1 + dp(i + 1, j + 1, n, m, a, b);
        else
            v[i][j] = max(dp(i + 1, j, n, m, a, b), dp(i, j + 1, n, m, a, b));
        return v[i][j];
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        memset(v, -1, sizeof(v));
        return dp(0, 0, nums1.size(), nums2.size(), nums1, nums2);
    }
};
// Tabulation Approach
class Solution // Tabulation 98% faster, array is one hell of an optimisation
{              // 98% time efficient, 94% space efficient
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};