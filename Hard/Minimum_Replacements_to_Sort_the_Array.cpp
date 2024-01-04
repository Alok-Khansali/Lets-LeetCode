// Runtime: 339 ms, faster than 97.30% of C++ online submissions for Minimum Replacements to Sort the Array.
// Memory Usage: 53.6 MB, less than 100.00% of C++ online submissions for Minimum Replacements to Sort the Array.
class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        long long len = nums.size(), ans = 0, lim = nums[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            if (nums[i] <= lim)
                lim = nums[i];
            else
            {
                long long partitions = nums[i] / lim + (nums[i] % lim != 0);
                lim = nums[i] / partitions;
                ans += partitions - 1;
            }
        }
        return ans;
    }
};