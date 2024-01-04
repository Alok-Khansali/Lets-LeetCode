class Solution
{ // Runtime: 33 ms, faster than 98.62% of C++ online submissions for Coin Change.
  // Memory Usage: 9.9 MB, less than 97.58% of C++ online submissions for Coin Change.
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int dp[amount + 1];                  // Array just changed the game
        for (int i = 0; i < amount + 1; i++) // Array initialisation is faster than initialising a vector
            dp[i] = amount + 1;              // Number of coins can never be greater than the amount [Fact!!!]

        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
            for (int j : coins)
                if (i >= j) // Gives the min number of coin to set up the current amount
                {
                    dp[i] = min(dp[i], 1 + dp[i - j]); // 1 for the current coin and added to the smallest combination for (i - current coin)
                }                                      // This builds the solution for the net amount

        return ((dp[amount] <= amount) ? dp[amount] : -1);

        /*
        if(dp[amount] <= amount)                           //In case the amount can be achieved, return the answer
            return dp[amount];
        return -1;                                         //Otherwise the value at dp[amount] will be amount + 1. Hence impossible to achieve, return -1
        */
    }
};

/*
//Vectors are Slow but have more functionalities
class Solution
{ // Runtime: 114 ms, faster than 54.15% of C++ online submissions for Coin Change.
  // Memory Usage: 14.3 MB, less than 68.59% of C++ online submissions for Coin Change.
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;

        vector<int> dp(amount + 1, amount + 1); // Number of coins can never be greater than the amount [Fact!!!]
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
            for (int j : coins)
                if (i >= j) // Gives the min number of coin to set up the current amount
                {
                    dp[i] = min(dp[i], 1 + dp[i - j]); // 1 for the current coin and added to the smallest combination for (i - current coin)
                }                                      // This builds the solution for the net amount

        if (dp[amount] <= amount) // In case the amount can be achieved, return the answer
            return dp[amount];
        return -1; // Otherwise the value at dp[amount] will be amount + 1. Hence impossible to achieve, return -1
    }
};
*/