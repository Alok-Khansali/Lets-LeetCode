// Slowest approach: Close the ends and then find the available cells
class Solution
{
public:
    void Close(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return;
        if (grid[i][j] <= 0)
            return;
        grid[i][j] = -1;
        Close(grid, i, j - 1);
        Close(grid, i, j + 1);
        Close(grid, i + 1, j);
        Close(grid, i - 1, j);
    }
    int count(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j] <= 0)
            return 0;
        if (grid[i][j] == 2)
            return 0;
        grid[i][j] = 2;
        int lt = count(grid, i, j - 1), rt = count(grid, i, j + 1);
        int up = count(grid, i - 1, j), dn = count(grid, i + 1, j);
        return 1 + lt + up + rt + dn;
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int islands = 0, col = grid[0].size(), row = grid.size(), moves = 0;
        for (int i = 0; i < row; i++)
        {
            if (grid[i][0] == 1)
                close(grid, i, 0);
            if (grid[i][col - 1] == 1)
                close(grid, i, col - 1);
        }
        for (int i = 0; i < col; i++)
        {
            if (grid[0][i] == 1)
                close(grid, 0, i);
            if (grid[row - 1][i] == 1)
                close(grid, row - 1, i);
        }
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                 moves = max(moves, count(grid, i , j);
        return moves;
    }
};
// Approach 2 : Slighly improving the previous one
class Solution // Bad and Slow first Draft
{
public:
    void close(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return;
        if (grid[i][j] <= 0)
            return;
        grid[i][j] = -1;
        close(grid, i, j - 1);
        close(grid, i, j + 1);
        close(grid, i + 1, j);
        close(grid, i - 1, j);
    }
    int count(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return -1e6;
        if (grid[i][j] <= 0)
            return 0;
        if (grid[i][j] == 2)
            return 0;
        grid[i][j] = 2;
        int lt = count(grid, i, j - 1), rt = count(grid, i, j + 1);
        int up = count(grid, i - 1, j), dn = count(grid, i + 1, j);
        return (1 + lt + up + rt + dn);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int islands = 0, col = grid[0].size(), row = grid.size(), moves = 0;
        for (int i = 1; i < row - 1; i++)
            for (int j = 1; j < col - 1; j++)
                if (grid[i][j] == 1)
                {
                 if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
                     close(grid, i, j);
                 else
                     moves += max(0, count(grid, i, j));
                }
        return moves;
    }
};
// Approach 3 : No closing just counting, short and sleek
class Solution
{
public:
    int count(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j] == 1 && (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1))
            return -1e6;
        if (grid[i][j] == 2 || grid[i][j] == 0)
            return 0;
        grid[i][j] = 2;
        int lt = count(grid, i, j - 1), rt = count(grid, i, j + 1);
        int up = count(grid, i - 1, j), dn = count(grid, i + 1, j);
        return (1 + lt + up + rt + dn);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int islands = 0, col = grid[0].size(), row = grid.size(), moves = 0;
        for (int i = 1; i < row - 1; i++)
            for (int j = 1; j < col - 1; j++)
                if (grid[i][j] == 1)
                 moves += max(0, count(grid, i, j));
        return moves;
    }
};
// Approach 4 : just close, and count number of 1s, fastest so far 91.94%
class Solution
{
public:
    void close(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())
            return;
        if (grid[i][j] <= 0)
            return;
        grid[i][j] = -1;
        close(grid, i, j - 1);
        close(grid, i, j + 1);
        close(grid, i + 1, j);
        close(grid, i - 1, j);
    }
    int count(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j] <= 0)
            return 0;
        if (grid[i][j] == 2)
            return 0;
        grid[i][j] = 2;
        int lt = count(grid, i, j - 1), rt = count(grid, i, j + 1);
        int up = count(grid, i - 1, j), dn = count(grid, i + 1, j);
        return (1 + lt + up + rt + dn);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int islands = 0, col = grid[0].size(), row = grid.size(), moves = 0;
        for (int i = 0; i < row; i++)
        {
            if (grid[i][0] == 1)
                close(grid, i, 0);
            if (grid[i][col - 1] == 1)
                close(grid, i, col - 1);
        }
        for (int i = 0; i < col; i++)
        {
            if (grid[0][i] == 1)
                close(grid, 0, i);
            if (grid[row - 1][i] == 1)
                close(grid, row - 1, i);
        }
        for (int i = 1; i < row - 1; i++)
            for (int j = 1; j < col - 1; j++)
                if (grid[i][j] == 1)
                 moves += count(grid, i, j);
        return moves;
    }
};