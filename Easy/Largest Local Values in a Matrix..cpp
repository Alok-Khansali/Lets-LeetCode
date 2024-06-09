class Solution // 4ms - 95% faster
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        ios_base::sync_with_stdio(0);
        int len = grid.size();
        vector<vector<int>> ans(len - 2, vector<int>(len - 2));
        for (int i = 0; i < len - 2; i++)
        {
            for (int j = 0; j < len - 2; j++)
            {
                int row = max({grid[i][j], grid[i][j + 1], grid[i][j + 2]});
                row = max({row, grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2]});
                row = max({row, grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]});
                ans[i][j] = row;
            }
        }
        return ans;
    }
};