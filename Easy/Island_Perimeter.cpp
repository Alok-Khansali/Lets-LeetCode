// Approach 1 : Too Many condition
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long s = 0, row = grid.size(), column = grid[0].size();
        for (int i = 0; i < column; i++)
            s += grid[0][i] + grid[row - 1][i];
        for (int i = 0; i < row; i++)
            s += grid[i][0] + grid[i][column - 1];
        for (int i = 0; i < row; i++)
            for (int j = 1; j < column; j++)
                s += abs(grid[i][j] - grid[i][j - 1]);
        for (int i = 0; i < column; i++)
            for (int j = 1; j < row; j++)
                s += abs(grid[j][i] - grid[j - 1][i]);
        return (s);
    }
};
// Declutter the conditions
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0, row = grid.size(), column = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                // Either top row, or upper row is water
                perimeter += (i == 0 || grid[i - 1][j] == 0) +
                             // Either end row or the row after is water
                             (i == row - 1 || grid[i + 1][j] == 0) +
                             // Either first column or column behind is water
                             (j == 0 || grid[i][j - 1] == 0) +
                             // Either last column or the column after is water
                             (j == column - 1 || grid[i][j + 1] == 0);
            }
        }
        return (perimeter);
    }
};
// Even less conditions
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        ios_base::sync_with_stdio(0);
        int perimeter = 0, row = grid.size(), column = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                // A land cell can contribute at most 4
                perimeter += 4;
                // A neighbouring top land cell, means a 2 deduction in the contribution
                perimeter -= (i > 0 || grid[i - 1][j] == 1) * 2;
                // A neighbouring left land cell, means a 2 deduction in the contribution
                perimeter -= (j > 0 || grid[i][j - 1] == 1) * 2;
            }
        }
        return (perimeter);
    }
};
// BFS
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        const int di[4] = {1, -1, 0, 0};
        const int dj[4] = {0, 0, 1, -1};
        int cnt = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    q.emplace(i, j); // starting cell
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            if (grid[i][j] != 1)
                continue;
            grid[i][j] = 2;
            for (int k = 0; k < 4; k++)
            {
                int r = i + di[k], s = j + dj[k];
                if (r < 0 || r >= n || s < 0 || s >= m || grid[r][s] == 0)
                {
                    cnt++;
                    continue;
                }
                if (grid[r][s] == 1)
                    q.emplace(r, s);
            }
        }
        return cnt;
    }
};
// dfs
#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    const int di[4] = {1, -1, 0, 0};
    const int dj[4] = {0, 0, 1, -1};
    int cnt = 0;
    int n, m;
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
        {
            cnt++;
            return;
        }
        if (grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        for (int k = 0; k < 4; k++)
        {
            int r = i + di[k], s = j + dj[k];
            dfs(r, s, grid);
        }
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                { // starting cell
                    dfs(i, j, grid);
                    goto done; // evil but easiest way
                }
    done:
        return cnt;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
