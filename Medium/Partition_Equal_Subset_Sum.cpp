class Solution
{
public:
    bool tell_me(int sum, vector<int> &nums)
    {
        int l = nums.size();
        vector<vector<bool>> dp((sum / 2 + 1), vector<bool>((l + 1), true));
        for (int i = 1; i <= sum / 2; i++)
            dp[i][0] = false;
        for (int i = 1; i <= sum / 2; i++)
            for (int j = 1; j <= l; j++)
            {
                dp[i][j] = dp[i][j - 1];
                if (i >= nums[j - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - nums[j - 1]][j - 1];
                }
            }
        return dp[sum / 2][l];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        return tell_me(sum, nums);
    }
};
// Approach: 2
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2)
            return false;
        bitset<10001> bit(1);
        for (auto i : nums)
        {
            bit |= bit << i;
            if (bit[s / 2])
                return bit[s / 2];
        }
        return bit[s / 2];
    }
};
