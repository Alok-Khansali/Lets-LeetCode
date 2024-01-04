// Approach 1
class Solution
{ // Runtime: 8 ms, faster than 95.19% of C++ online submissions for Transpose Matrix.
  // Memory Usage: 10.6 MB, less than 43.03% of C++ online submissions for Transpose Matrix.
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int x = matrix.size(), y = matrix[0].size(); // getting the number of rows and columns
        vector<vector<int>> res(y, vector<int>(x));  // Creating a transpose matrix [columns x rows]
        for (int i = 0; i < y; i++)
            for (int j = 0; j < x; j++)
                res[i][j] = matrix[j][i]; // Filling the matrix, (i,j)th cell in res is to be filled with (j,i)th cell in matrix
        return res;
    }
};



// Approach 2
class Solution
{ // Runtime: 20 ms, faster than 27.23% of C++ online submissions for Transpose Matrix.
  // Memory Usage: 10.6 MB, less than 43.03% of C++ online submissions for Transpose Matrix.
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int R = matrix.size(), C = matrix[0].size(); // getting the number of rows and columns
        int MIN = min(R, C), diff = abs(R - C);
        for (int i = 0; i < MIN; i++)     // For a square matrix , just swapping the (i,j)th cell with (j,i)th cell works
            for (int j = i; j < MIN; j++) // The dimension is halved because (j,i)th cell is on the other side of the diagonal
                swap(matrix[i][j], matrix[j][i]);
        if (R < C) // When rows < columns, resizing is an issue
        {
            for (int i = MIN; i < C; i++)
            {
                vector<int> v;
                for (int j = 0; j < R; j++) // Combining extra columns elements to a since vector
                    v.push_back(matrix[j][i]);
                matrix.push_back(v); // Adding this combine column vector as a new row to the matrix
            }
            // Resizing as [C x R]
            for (int i = 0; i < MIN; i++) // Resize all the rows with extra elements
                matrix[i].resize(R);
        }
        else if (C < x) // When rows < column, it gets easier
        {
            for (int i = 0; i < MIN; i++)
                for (int j = MIN; j < R; j++)
                    matrix[i].push_back(matrix[j][i]); // All the extra column elements in the (i)th column,will be pushed to (i)th row
            matrix.resize(C);                          // Since all the rows will with less elements are to be ignored, simply resize to y
        }
        return matrix;
    }
};