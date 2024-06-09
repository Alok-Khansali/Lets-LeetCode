class Solution // Using the extra space, 97% faster
{
public:
    int minFallingPathSum(vector<vector<int>> &A)
    {
        if (A.empty() || A[0].empty())
            return 0;
        int m = A.size(), n = A[0].size(), answer = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n + 2, INT_MAX));
        // Load the last row of the Array into the DP array
        for (int j = 1; j <= n; j++)
            dp[m - 1][j] = A[m - 1][j - 1];
        for (int i = m - 2; i >= 0; i--)
            for (int j = 1; j <= n; j++)
                dp[i][j] = A[i][j - 1] + min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
        for (int i = 1; i <= n; i++)
            answer = min(answer, dp[0][i]);
        return answer;
    }
};

// No Extra Space
// If one wants that the given array is not manipulated, one can simply remove & in vector<vector<int>> &A
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &A)
    {
        if (A.empty() || A[0].empty())
            return 0;
        int m = A.size(), n = A[0].size(), answer = INT_MAX;
        for (int i = m - 2; i >= 0; i--)
            for (int j = 0; j < n; j++)
            {
                int lt = (j > 0) ? A[i + 1][j - 1] : INT_MAX;
                int rt = (j < n - 1) ? rt = A[i + 1][j + 1] : INT_MAX;
                A[i][j] += min(A[i + 1][j], min(lt, rt));
            }
        for (int i = 0; i < n; i++)
            answer = min(answer, A[0][i]);
        return answer;
    }
};