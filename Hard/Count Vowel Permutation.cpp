// Approach 1
// Basic Recursive solution, Gives TLE
/*
Idea here is to get to the second last character of a permutation
And add the options available to it

But something better needs to be searched in this solution to get
a solution with better time complexity
*/
class Solution
{
public:
    long long int m = 1e9 + 7, sum = 0;
    vector<vector<char>> v;
    void ans(char c, int i, int n)
    {
        int x = (c - 'a' + 2) / 5; // to get the index of character in the vowels
        // When we are at the second last character of a permutation, return number of vowels that can follow it
        if (i == n - 1)
        {
            sum = (sum + (v[0][x] - '0')) % m;
            return;
        }

        // Otherwise check for all the characters availabe to the current vowel
        for (int j = 0; j < v[x + 1].size(); j++)
            ans(v[x + 1][j], i + 1, n); // Raising the character limit, i+1
    }
    int countVowelPermutation(int n)
    {
        ios_base::sync_with_stdio(0);
        if (n == 1)
            return 5;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        // v[0] = number of vowels the can follow a vowel in the above array
        // v[1] = combination available to a
        // v[2] = combination available to e
        // v[3] = combination available to i
        // v[4] = combination available to o
        // v[5] = combination available to u
        v = {{'1', '2', '4', '2', '1'}, {'e'}, {'a', 'i'}, {'a', 'e', 'o', 'u'}, {'i', 'u'}, {'a'}};

        // Journey of every permutation begins with a single vowel
        for (int i = 0; i < 5; i++)
            ans(vowels[i], 1, n);
        return sum;
    }
};

// Aproach 2
// DP = Dhaasu Programming
/*
You see this question and you are afraid coz this is hard and also coz you know you will be using DP
And since you are a noob like me, you for recursion, and then u solve it but u get TLE,
U are crying but suddenly u realise that you also know you can do memoisation, but how?

Up until now, as per my approach 1, i wanted to reach the second last character and get its available options
But what if i store the permutations available to each vowel at a certain level?
Then i will only have to recursively solve for those levels for which are not yet calculated

This will give me the total permutations available to each vowel
So the final answer will be the sum of all the permutations available to each vowel and that to in the mod of m
*/

class Solution // Runtime: 53 ms, faster than 60.44% of C++ online submissions for Count Vowels Permutation.
// Memory Usage: 8.9 MB, less than 64.95% of C++ online submissions for Count Vowels Permutation.
{
public:
    long long int m = 1e9 + 7, res = 0;
    vector<vector<char>> v;
    long dp[5][20001];
    int ans(char c, int i, int n)
    {
        int x = (c - 'a' + 2) / 5; // to get the index of character in the vowels
        // When we are at the second last character of a permutation, return number of vowels that can follow it
        if (i == n - 1)
            return dp[x][2];
        // If the combinations for the given position is not 0, return it
        if (dp[x][n - i] != 0)
            return (dp[x][n - i] % m);
        // Otherwise check for all the characters availabe to the current vowel
        for (int j = 0; j < v[x].size(); j++)
            // Storing the permutation for the current level for a given vowel
            dp[x][n - i] = (dp[x][n - i] + ans(v[x][j], i + 1, n)) % m; // Raising the character limit, i+1
        return dp[x][n - i];
    }
    int countVowelPermutation(int n)
    {
        ios_base::sync_with_stdio(0);
        if (n < 3)
            return n * 5;
        memset(dp, 0, sizeof(dp));
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        // v[0] = number of vowels the can follow a vowel in the above array
        // v[1] = combination available to a
        // v[2] = combination available to e
        // v[3] = combination available to i
        // v[4] = combination available to o
        // v[5] = combination available to u
        v = {{'e'}, {'a', 'i'}, {'a', 'e', 'o', 'u'}, {'i', 'u'}, {'a'}};
        // Journey of every permutation begins with a single vowel
        for (int i = 0; i < 5; i++)
            dp[i][1] = 1;
        // options for a, u
        dp[0][2] = dp[4][2] = 1;
        // options for e, o
        dp[1][2] = dp[3][2] = 2;
        // options for i
        dp[2][2] = 4;
        for (int i = 0; i < 5; i++)
            res = (res + ans(vowels[i], 1, n + 1)) % m;
        return res;
    }
};

// Approach 3
// Time to go linear
// 2D to no dp
// Every chsrscter is related, but how
// Thats the pattern and the answer
class Solution // Runtime: 2 ms, faster than 95.95% of C++ online submissions for Count Vowels Permutation.
// Memory Usage: 5.9 MB, less than 95.33% of C++ online submissions for Count Vowels Permutation.
{
public:
    int countVowelPermutation(int n)
    {
        long aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        int MOD = 1000000007;

        for (int i = 1; i < n; i++)
        {
            long aCountNew = (eCount + iCount + uCount) % MOD;
            long eCountNew = (aCount + iCount) % MOD;
            long iCountNew = (eCount + oCount) % MOD;
            long oCountNew = (iCount) % MOD;
            long uCountNew = (iCount + oCount) % MOD;
            aCount = aCountNew;
            eCount = eCountNew;
            iCount = iCountNew;
            oCount = oCountNew;
            uCount = uCountNew;
        }
        long result = (aCount + eCount + iCount + oCount + uCount) % MOD;
        return (int)result;
    }
};