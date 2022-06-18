class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Triangle.
  // Memory Usage: 8.5 MB, less than 91.19% of C++ online submissions for Triangle.
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int len = triangle.size();
        for (int i = len - 2; i >= 0; i--) // Building the solution Bottom-Up
        {
            for (int j = 0; j < triangle[i].size(); j++) // Traversing the current row
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]); // Add the minimum of the two available options
            }
        }
        return triangle[0][0]; // As the result will be stored in the top-most element, return the top-most element
    }
};