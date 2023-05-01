class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        vector<pair<int, int>> vp(arr.size() + 1);
        vector<int> row(mat.size(), 0), col(mat[0].size(), 0);
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                vp[mat[i][j]] = {i, j};
        for (int i = 0; i < r * c; i++)
        {
            row[vp[arr[i]].first]++;
            col[vp[arr[i]].second]++;
            if (row[vp[arr[i]].first] == c || col[vp[arr[i]].second] == r)
                return i;
        }
        return r * c - 1;
    }
};