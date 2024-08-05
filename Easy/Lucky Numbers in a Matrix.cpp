class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int numRows = matrix.size(), numCols = matrix[0].size(), maxRowMin = INT_MIN, minColMax = INT_MAX;
        for (int i = 0; i < numRows; i++)
        {
            int rowMin = INT_MAX;
            for (int j = 0; j < numCols; j++)
                rowMin = min(rowMin, matrix[i][j]);
            maxRowMin = max(maxRowMin, rowMin);
        }
        for (int i = 0; i < numCols; i++)
        {
            int colMax = INT_MIN;
            for (int j = 0; j < numRows; j++)
                colMax = max(colMax, matrix[j][i]);
            minColMax = min(minColMax, colMax);
        }
        if (maxRowMin == minColMax)
            return {maxRowMin};
        return {};
    }
};