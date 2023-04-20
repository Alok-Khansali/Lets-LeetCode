class Solution //70% faster
{
public:
    void dfs(int i, int j, vector<vector<char>> &g, int n, int m)
    {
        if (i == n || j == m || i == -1 || j == -1 || (g[i][j] - '0') % 2 == 0)
            return;
        g[i][j] = '2';
        dfs(i + 1, j, g, n, m); // Down
        dfs(i, j + 1, g, n, m); // Right
        dfs(i, j - 1, g, n, m); // Left
        dfs(i - 1, j, g, n, m); // Down
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, grid, n, m);
                }
        return ans;
    }
};