class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        // LCS with addition of characters
        int l1 = s1.size(), l2 = s2.size();
        int dp[l1 + 1][l2 + 1];
        // Assuming the strings to be made equal as empty
        dp[0][0] = 0;
        // Base Case, if all the characters of the second string are to be removed
        for (int i = 1; i <= l2; i++)
            dp[0][i] = dp[0][i - 1] + s2[i - 1];
        // Base Case, if all the characters of the first string are to be removed
        for (int i = 1; i <= l1; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        // Now if the character of string s1 at index (i -1) doesnt match with the
        // character of string s2 at index (j -1)
        // Then either remove the (i-1)th character of s1
        // Or remove the (j-1)th character of the string s2
        // Else use the value that is diagonally preceding the curent value in the dp-array
        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++)
                if (s1[i - 1] != s2[j - 1])
                    dp[i][j] = min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j - 1];
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
                cout << dp[i][j] << ' ';
            cout << '\n';
        }
        return dp[l1][l2];
    }
};