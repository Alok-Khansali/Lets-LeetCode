class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<int> dir = {-1, 0, 1};
        int row = grid.size(), col = grid[0].size(), ans = 0, col1 = 0, col2 = col - 1;
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        ans = dp[0][col1][col2] = grid[0][col1] + grid[0][col2];

        for (int i = 1; i < row; i++)
            for (int c1 = 0; c1 < col; c1++)
                for (int c2 = 0; c2 < col; c2++)
                {
                    int prev = dp[i - 1][c1][c2];
                    if (prev >= 0)
                    {
                        for (int d1 : dir)
                        {
                            col1 = d1 + c1;
                            for (int d2 : dir)
                            {
                                col2 = d2 + c2;
                                if (inRange(col1, col) && inRange(col2, col))
                                {
                                    dp[i][col1][col2] = max(dp[i][col1][col2], prev + (col1 == col2 ? grid[i][col1] : (grid[i][col1] + grid[i][col2])));
                                    ans = max(ans, dp[i][col1][col2]);
                                }
                            }
                        }
                    }
                }
        return ans;
    }
    bool inRange(int val, int limit)
    {
        return 0 <= val && val < limit;
    }
};