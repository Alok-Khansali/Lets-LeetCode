// Killshot
class Solution // Runtime: 68 ms, faster than 98.41% of C++ online submissions for Ones and Zeroes.
               // Memory Usage: 8.6 MB, less than 98.79% of C++ online submissions for Ones and Zeroes.
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int dp[101][101]{0}; // Initialising the array then and there, but requires constant bounds, no variableS
        // memset(dp,0,sizeof(dp));

        for (string s : strs)
        {
            int z = 0, o = 0; // to store the counts for zeroes and ones
            for (char c : s)  // Getting the number of zeroes and ones
                z += (c == '0'), o += (c == '1');   //Can also use the count()

            for (int i = m; i >= z; i--)     // for every string getting the combination for
                for (int j = n; j >= o; j--) // zeroes and ones, when a string is either used or rejected
                    dp[i][j] = max(dp[i][j], 1 + dp[i - z][j - o]);
        }
        return dp[m][n];
    }
};
// TIME COMPLEXITY : O(N^3)

// METHOD 2

/* SECOND ATTEMPT TRYING TO REDUCE THE 3D TO 2D DP
class Solution // Runtime: 135 ms, faster than 93.58% of C++ online submissions for Ones and Zeroes.
               // Memory Usage: 8.8 MB, less than 94.19% of C++ online submissions for Ones and Zeroes.
{
public:
    int *zero_one(string s) // Sending the array containg counts for zeroes and ones
    {
        int arr[2] = {0, 0};
        for (char c : s) // Getting the number of zeroes and ones
            arr[0] += (c == '0'), arr[1] += (c == '1');
        return arr;
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        ios_base::sync_with_stdio(0);
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (string s : strs)
        {
            int *a = zero_one(s); // Getting the count for the current String
            for (int i = m; i >= a[0]; i--)
                for (int j = n; j >= a[1]; j--)
                    dp[i][j] = max(dp[i][j], 1 + dp[i - a[0]][j - a[1]]);
        }
        return dp[m][n];
    }
};



//METHOD 3

/* First Draft using 3D DP
class Solution
{
    // Runtime: Runtime: 905 ms, faster than 10.74% of C++ online submissions for Ones and Zeroes.
    // Memory Usage: 35.7 MB, less than 51.78% of C++ online submissions for Ones and Zeroes.
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