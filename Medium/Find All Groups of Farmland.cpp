class Solution
{
public:
    void dfs(vector<vector<int>> &land, int i, int j, int &r2, int &c2)
    {
        if (i >= land.size() || j >= land[0].size() || land[i][j] % 2 == 0)
            return;
        if (r2 < i)
            r2 = i, c2 = j;
        else if (c2 < j)
            c2 = j;
        land[i][j] = 2;
        dfs(land, i + 1, j, r2, c2);
        dfs(land, i - 1, j, r2, c2);
        dfs(land, i, j + 1, r2, c2);
        dfs(land, i, j - 1, r2, c2);
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[0].size(); j++)
            {
                if (land[i][j] == 1)
                {
                    int r2 = i, c2 = j;
                    dfs(land, i, j, r2, c2);
                    ans.push_back({i, j, r2, c2});
                }
            }
        }
        return ans;
    }
};