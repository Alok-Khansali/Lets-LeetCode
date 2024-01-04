class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == 1)
                    mat[i][j] = n * m;
                else
                    q.push({i, j});
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            for (vector<int> v : dir)
            {
                int r = i + v[0], c = j + v[1];
                if (r < n && c < m && r >= 0 && c >= 0 && mat[r][c] == n * m)
                {
                    mat[r][c] = mat[i][j] + 1;
                    q.push({r, c});
                }
            }
            q.pop();
        }
        return mat;
    }
};