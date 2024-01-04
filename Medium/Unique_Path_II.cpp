class Solution // Runtime: 3 ms, faster than 80.74% of C++ online submissions for Unique Paths II.
               // Memory Usage: 7.5 MB, less than 98.16% of C++ online submissions for Unique Paths II.
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // If the syarting cell is an obstacle
        // There will be no way to reach the bottom-right cell
        // Hence return 0
        if (obstacleGrid[0][0])
            return 0;
        // For any given cell best a robot can do is to
        // Go down or go right
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;

        for (int i = 1; i < m; i++)     // For the top row, cells can only be reached from the left (previous column)
            // if at (i,j) obstacle is present, set it to 0 ===> No contribution
            // Otherwise Set it equal the cell just left of it
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0) ? obstacleGrid[0][i - 1] : 0;

        for (int i = 1; i < n; i++) 
        // Similarily for the leftmost column, only way to travel is down
        // And therefore it can only be reached from the up (previous row)
        obstacleGrid[i][0] = (obstacleGrid[i][0] == 0) ? obstacleGrid[i - 1][0] : 0;

        for (int i = 1; i < n; i++)     // For any other cell, the number of ways to reach it is equal to the number of ways to
            for (int j = 1; j < m; j++) // reach the cell to its left and the cell above it
                if (obstacleGrid[i][j]) // if at (i,j) obstacle is present, set it to 0 ===> No contribution
                    obstacleGrid[i][j] = 0;
                else                                                                      // The number of ways to reach the cell is equal to the number of ways to
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]; // reach the cell above it + the number of ways to reach the cell to its left

        return obstacleGrid[n - 1][m - 1];
    }
};

// Extra Space Shorter Code
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
// Memory Usage: 7.9 MB, less than 25.25% of C++ online submissions for Unique Paths II.
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // If the starting point is an obstacle
        // there is no way to reach th e bottom- right cell
        if (obstacleGrid[0][0] == 1)
            dp[1][1] = 1;
        // Set the starting point as 1
        // Always 1 way to reach this cell, in case its not an obstacle
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // Now for every cell that is not an obstacle
        // The number of ways to reach it is the sum of
        // Number of ways to reach the cell to its left4
        // And the number of ways to reach the cell above it
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (obstacleGrid[i - 1][j - 1] != 1)
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};