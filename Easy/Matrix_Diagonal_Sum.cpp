class Solution 
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), col = m, ans = 0;
        for (int i = 0; i < n; i++)
            ans += mat[i][i];
        for (int i = 0; i < n; i++)
            ans += mat[i][--col];
        if ((n & 1) && (m & 1))
            ans -= mat[n / 2][n / 2];
        return ans;
    }
};