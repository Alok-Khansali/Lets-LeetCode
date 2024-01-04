class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int row = 0, col = 0, number = 1, c = 0;
        while (c < (n + 1) / 2) // Filling the matrix in squares, starting from the outermost and then going inwards
        {
            row = sqr_count, col = sqr_count;
            for (; col < n - sqr_count - 1; col++) // Going from first element of the square to the second last in that row
                ans[row][col] = number++;
            for (; row < n - sqr_count - 1; row++) // Going from the last row element(first in the column) to the second last in that column
                ans[row][col] = number++;
            for (; col > sqr_count; col--) // From the last element in the last column(last row element) to the second element in the bottom row
                ans[row][col] = number++;
            for (; row > sqr_count; row--) // From the last element in the last row,(last column element) to the second element in the first column
                ans[row][col] = number++;
            sqr_count++;
        }
        if (n & 1)  // If the order of matrix is odd set the maximum in the center
            ans[n / 2][n / 2] = r;
        return ans;
    }
};