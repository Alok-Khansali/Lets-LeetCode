class Solution
{
  // Runtime: 74 ms, faster than 42.07% of C++ online submissions for Longest Increasing Path in a Matrix.
  // Memory Usage: 16 MB, less than 55.62% of C++ online submissions for Longest Increasing Path in a Matrix.
public:
  int n, m;
  vector<vector<int>> test;
  int rec(vector<vector<int>> &mt, int i, int j, int val) // Pre-compute the result,
  {                                                       // if the value has been traversed return the value at that point
    if (i < 0 || i >= n || j < 0 || j >= m)
      return 0;

    if (mt[i][j] <= val) // If the value is not greater than the current val,
      return 0;          // the searching ends, no point of traversing further

    if (test[i][j] != 0) // If the position has been traversed, return the value at that position
      return test[i][j];

    // Raise the bar,give val, the current higher value
    val = mt[i][j]; // Prevents checking the matrix matrix 4 times

    // Minimum length will always be 1, 1 is added to show that the current state contribute at least 1 in length, i.e. itself
    test[i][j] = (1 + max({rec(mt, i + 1, j, val), rec(mt, i, j + 1, val),    // Check all the 4 available directions, and store at the
                           rec(mt, i - 1, j, val), rec(mt, i, j - 1, val)})); // anser at the (i,j) index in the test matrix

    return test[i][j];
  }
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    int ans = 0;
    n = matrix.size(), m = matrix[0].size();
    test.resize(n, vector<int>(m, 0)); // Resizing the global vector, setting all values as 0, stating untraversed
    test[0][0] = 1;                    // The first value will have the longest path of 1, so...
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
        int val = matrix[i][j];                                                                                                                    // Prevents checking the matrix matrix 4 times
        ans = max(ans, 1 + max({rec(matrix, i - 1, j, val), rec(matrix, i + 1, j, val), rec(matrix, i, j - 1, val), rec(matrix, i, j + 1, val)})); // Check all the valid four directions
      }
    return ans;
  }
};

/*
//Only Recursion, gets TLE, (coz of the overlapping problems) for the 23 test cases
class Solution {
public:
    int n,m;
    int rec(vector<vector<int>>& mt ,int i , int j, int val)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if(mt[i][j] <= val)
            return 0;
        val = mt[i][j];
        return (1 + max({rec(mt, i+1,j,val),rec(mt, i,j+1,val),rec(mt, i-1,j,val),rec(mt, i,j-1,val)}));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int ans = 0;
        n = matrix.size(), m = matrix[0].size();
        for(int i = 0;i < n;i++)
            for(int j = 0; j < m;j++)
            {
                int val = matrix[i][j];
                ans = max(ans, 1 + max({rec(matrix,i - 1,j, val), rec(matrix,i + 1,j, val), rec(matrix,i,j - 1, val), rec(matrix,i,j + 1,val)}));
            }
        return ans;
    }
};
*/