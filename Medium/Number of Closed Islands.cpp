class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<vector<bool>> visit(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, grid, visit))
                    count++;
        return count;
    }
    bool bfs(int x, int y, int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &visit)
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        visit[x][y] = 2;
        bool isClosed = true;
        vector<int> dirx{0, 1, 0, -1}, diry{-1, 0, 1, 0};
        while (!q.empty())
        {
            // row number & column number
            x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int r = x + dirx[i], c = y + diry[i];
                if (r < 0 || r >= m || c < 0 || c >= n)
                    // (x, y) is a boundary cell.
                    isClosed = false;
                else if (grid[r][c] == 0 && !visit[r][c])
                {
                    q.push({r, c});
                    visit[r][c] = true;
                }
            }
        }
        return isClosed;
    }
};
// Approach 2
class Solution
{
public:
    bool isClosed(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return false;
        if (grid[i][j] >= 1)
            return true;
        grid[i][j] = 2; // Traversed, hence marked 2, any number greater than 1 works
        // Check if all sides around are closed
        bool lt = isClosed(grid, i, j - 1), rt = isClosed(grid, i, j + 1), up = isClosed(grid, i + 1, j), dn = isClosed(grid, i - 1, j);
        return lt && rt && up && dn;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 0 && isClosed(grid, i, j))
                    islands++;
        return islands;
    }
};