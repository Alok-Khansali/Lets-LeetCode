// Method 1 : create a new matrix and do the thing O(mn)
// Method 2 : store the rows and columns which have a zero, and then set all those rows and cols as 0 O(m + n)
// Or the method i finally deduced, solving via method 2
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> r, c;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0)
                    r.insert(i), c.insert(j);
        for (int col : c)
            for (int i = 0; i < n; i++)
                matrix[i][col] = 0;
        for (int row : r)
            for (int i = 0; i < m; i++)
                matrix[row][i] = 0;
    }
};
// Or the method i finally deduced, solving via method 2, O(1) space
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), isro = 0, isco = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        isro = 1;
                    if (j == 0)
                        isco = 1;
                    matrix[i][0] = 0, matrix[0][j] = 0;
                }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if (isco)
            for (int i = 1; i < n; i++)
                matrix[i][0] = 0;
        if (isro)
            for (int i = 1; i < m; i++)
                matrix[0][i] = 0;
    }
};