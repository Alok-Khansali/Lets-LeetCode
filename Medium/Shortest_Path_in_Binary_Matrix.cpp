class Solution
{
public:
    bool isValid(int r, int c, int n, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        return (r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == 0 && !visited[r][c]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), ans = 0, size;
        queue<pair<int, int>> q;                                 // it stores visited cells
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // it stores status of  the cell
        if (!grid[0][0])                                         // if starting cell value is 0, put it into the queue
            q.push({0, 0}), visited[0][0] = true;
        while (!q.empty())
        {
            size = q.size(), ans++;
            for (int cnt = 0; cnt < size; cnt++)
            {
                auto node = q.front();
                q.pop();
                int i = node.first, j = node.second; // get row and column of the cell
                if (i == n - 1 && j == n - 1)
                    return ans; // if we reach end cell return ans
                for (int r = i - 1; r <= i + 1; r++)
                    for (int c = j - 1; c <= j + 1; c++)
                        if (isValid(r, c, n, grid, visited))
                            q.push({r, c}), visited[r][c] = true;
            }
        }
        return -1;
    }
};