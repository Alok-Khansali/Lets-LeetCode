class Solution // Memoisation Solution
{              // Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
public:
  // Global Arrays are initialised  to default values
  int dp[101];   // Array to store the max value
  bool chc[101]; // Array to check if the array position has been traversed or not,initially all the value will be 0 i.e. none traversed
  int loot(vector<int> &a, int i, int n)
  {
    if (i >= n) // If the length of the array has been reached then terminate
    {
      return 0;
    }

    if (chc[i]) // If the array position has been already reached the chc[i] position will have a value true
    {
      return dp[i]; // In that case return the value stored at i(th) position in the dp array
    }

    chc[i] = true; // Else set chec[i] as 1 or true

    dp[i] = max(loot(a, i + 1, n), a[i] + loot(a, i + 2, n)); // Find the max value recursively and store that in the i(th) position in the dp array

    return dp[i]; // when all is said and done, return the value stored at i(th) position in the dp array
  }
  int rob(vector<int> &nums)
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return loot(nums, 0, nums.size());
  }
};

// Tabulation
class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i)
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

    return dp[n - 1];
  }
};
