// Approach 1, using the combinatorics
class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths
  // Memory Usage: 5.9 MB, less than 70.03% of C++ online submissions for Unique Paths.
public:
    int uniquePaths(int m, int n)
    {
        // It can be easily deduced that, to reach the destination (m-1) moves are to be taken downwards and (n-1) moves to the right
        // The idea here is to choose either the (m-1) step down or (n-1) steps right out of (m+n-2) steps.
        // The one that is not choosen, say, the moves to the right, will just act as fillers in the path

        long result = 1, mx = max(n, m);                  // Take long datatype for result and since its confirmed that answer will be <= 2 * 10^9,it will easily be returned
        for (int i = mx, r = 1; i <= n + m - 2; i++, r++) // We know that max(m-1,n-1)! will be cancelled for sure from (m+n-2)!
        {                                                 // Therefore start from max(m,n) and start the smaller
            result = (result * i) / r;                    //(n + m -2) - (m - 1) = (n - 1), therefore 'r' will reach the max value of (n-1) and that is only required
        }
        return result; // Return the value for which the code was return
    }
};

// Approach two, using the dynamic programming
class Solution
{ // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
  // Memory Usage: 5.9 MB, less than 75.04% of C++ online submissions for Unique Paths.
public:
    int uniquePaths(int m, int n)
    {
        /*
        Since we can only travel in only two direction, i.e., rightwards and downwards
        Number of paths to reach a cell is equal to the number of ways to reach
        The Cell above it and The Cell to its Left
        */
        int ans[m + 1][n + 1];
        memset(a, 0, sizeof(a)); // All zero, nothing traversed
        ans[1][1] = 1;           // Start point
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                ans[i][j] += ans[i - 1][j] + ans[i][j - 1]; // Cell above and cell to the left
        return ans[m][n];
    }
};