class Solution //NlogN solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> row, col;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            row[grid[i]]++;
        for (int i = 0; i < m; i++)
        {
            vector<int> s;
            for (int j = 0; j < n; j++)
                s.push_back(grid[j][i]);
            col[s]++;
        }
        for (auto i : row)
        {
            int y = col[i.first];
            ans += (y * i.second);
        }
        return ans;
    }
};