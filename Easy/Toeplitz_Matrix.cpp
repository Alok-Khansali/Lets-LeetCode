class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int col = matrix[0].size(), row = matrix.size(), ans = col + row - 1;
        if (col == 1 || row == 1)
            return true;
        for (int i = 0; i < col; i++)
        {
            int x = matrix[0][i], k = 1, j = i + 1, c = 1;
            while (j < row && k < row)
            {
                if (x != matrix[k++][j++])
                {
                    c = 0;
                    break;
                }
            }
            ans -= (c != 0);
        }
        for (int i = 1; i < row; i++)
        {
            int x = matrix[i][0], k = 1, j = i + 1, c = 1;
            while (j < row && k < row)
            {
                if (x != matrix[j++][k++])
                {
                    c = 0;
                    break;
                }
            }
            ans -= (c != 0);
        }
        return (ans == 0);
    }
};