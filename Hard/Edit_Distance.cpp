// Tabulation
// bottom up approach - dp - The time complexity of the bottom-up approach is O(mn),
// where m and n are the lengths of the input strings word1 and word2.
// This is because we are computing each subproblem once,
// and we are using the results of the previous subproblems to compute the current subproblem.
// The space complexity of this approach is O(mn) as well,
// because we are using a two-dimensional array of size m*n to store the results of the subproblems.
// However, we can reduce the space complexity to O(min(m,n))
// by only storing the results of the current and previous rows of the two-dimensional array.

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            v[i][0] = i;
        for (int j = 0; j < n; j++)
            v[0][j] = j;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    v[i][j] = v[i - 1][j - 1];
                else
                    v[i][j] = min({v[i - 1][j] + 1, v[i][j - 1] + 1, v[i - 1][j - 1] + 1});
            }
        }
        return v[m][n];
    }
};

// memoisation
// memoization - top down approach - The time complexity of the top-down approach is O(mn),
// where m and n are the lengths of the input strings word1 and word2. This is because we are using memoization to avoid redundant computations,
// and we are only computing each subproblem once. The space complexity of this approach is O(mn) as well,
// because we are using a two-dimensional array of size m*n to store the results of the subproblems.
class Solution
{
public:
    int minDistanceHelper(string &word1, string &word2, vector<vector<int>> &dp, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == 0)
        {
            dp[i][j] = j;
            return j;
        }
        if (j == 0)
        {
            dp[i][j] = i;
            return i;
        }
        if (word1[i - 1] == word2[j - 1])
        {
            dp[i][j] = minDistanceHelper(word1, word2, dp, i - 1, j - 1);
        }
        else
        {
            // Insert a character into word1
            int insertOp = minDistanceHelper(word1, word2, dp, i, j - 1);
            // Delete a character from word1
            int deleteOp = minDistanceHelper(word1, word2, dp, i - 1, j);
            // Replace a character in word1 with a character in word2
            int replaceOp = minDistanceHelper(word1, word2, dp, i - 1, j - 1);
            dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return minDistanceHelper(word1, word2, dp, m, n);
    }
};

// Recursion
// Recursive approach - you will get TLE -
// The time complexity of the recursive approach is O(3^(m+n)),
// where m and n are the lengths of the input strings word1 and word2.
// This is because each recursive call can branch into three different recursive calls, leading to a total of 3^(m+n) recursive calls.
// The space complexity of this approach is also O(m+n) because of the space used by the function call stack.
class Solution
{
public:
    int minDistanceHelper(string word1, string word2, int m, int n)
    {
        if (m == 0)
            // If word1 is empty, insert all characters of word2
            return n;
        if (n == 0)
            // If word2 is empty, delete all characters of word1
            return m;
        if (word1[m - 1] == word2[n - 1])
            // Last characters match, no operation required
            return minDistanceHelper(word1, word2, m - 1, n - 1);
        else
        {
            // Insert a character into word1
            int insertOp = minDistanceHelper(word1, word2, m, n - 1);
            // Delete a character from word1
            int deleteOp = minDistanceHelper(word1, word2, m - 1, n);
            // Replace a character in word1 with a character in word2
            int replaceOp = minDistanceHelper(word1, word2, m - 1, n - 1);
            // Take the minimum of the three operations and add 1
            return 1 + min({insertOp, deleteOp, replaceOp});
        }
    }

    int minDistance(string word1, string word2)
    {
        return minDistanceHelper(word1, word2, word1.length(), word2.length());
    }
};