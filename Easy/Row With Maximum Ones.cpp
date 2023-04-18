class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int n = mat.size(), mx = -1, ans = -1;
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j : mat[i])
                c += j;
            if (c > mx)
                mx = c, ans = i;
        }
        return {ans, mx};
    }
};
// Using accumulate function