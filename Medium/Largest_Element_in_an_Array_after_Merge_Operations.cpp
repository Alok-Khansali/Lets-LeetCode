class Solution
{
public:
    long long maxArrayValue(vector<int> &nums)
    {
        long long len = nums.size(), curr_sum = nums[len - 1], ans = curr_sum;
        for (int i = len - 2; i >= 0; i--)
        {
            curr_sum = ((curr_sum >= nums[i]) ? curr_sum + nums[i] : nums[i]);
            ans = max(ans, curr_sum);
        }
        return ans;
    }
};