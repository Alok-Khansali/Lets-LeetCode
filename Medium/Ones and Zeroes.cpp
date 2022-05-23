
/* First Draft using 3D DP
class Solution
{
    // Runtime: 954 ms, faster than 9.86% of C++ online submissions for Ones and Zeroes.
    // Memory Usage: 35.9 MB, less than 43.94% of C++ online submissions for Ones and Zeroes.
public:
    // Initialising at maximum bounds
    int dp[101][101][600]; // vector<vector<vector<int>>> dp (if using a vector)
    int help(vector<string> &strs, int m, int n, int index)
    {
        if (index == strs.size() || m < 0 || n < 0) // If index is equal to the size of vector, or any (or both) of the counts are less than 0
            return 0;                               // return 0;

        if (dp[m][n][index] > 0) // If the such a combination of m,n,index has been reached, return it
            return dp[m][n][index];

        int z = 0, o = 0; // Storing the count for zeroes and ones

        for (char c : strs[index]) // Getting the number of zeroes and ones
            z += (c == '0'), o += (c == '1');

        if (m >= z && n >= o)                                          // Checking if its possible to use the current string, m >= zeroes and n >= ones
            dp[m][n][index] = 1 + help(strs, m - z, n - o, index + 1); // Storing the value after using the current string

        dp[m][n][index] = max(dp[m][n][index], help(strs, m, n, index + 1)); // Store the max of (used {from above}, left(The value recived after leaving the current string))

        return dp[m][n][index]; // Return the value for the current combination of {m,n,index}
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        ios_base::sync_with_stdio(false);
        // VECTOR:  Slow as always [Runtime: 1013 ms, faster than 8.55% of C++ online submissions for Ones and Zeroes.]
        // dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size()+1,0))); //Resizing a 3d Vector
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= strs.size(); k++)
                    dp[i][j][k] = 0;
        return help(strs, m, n, 0);
    }
};
*/