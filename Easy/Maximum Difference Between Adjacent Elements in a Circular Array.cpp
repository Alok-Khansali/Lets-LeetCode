class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int len = nums.size(), ans = abs(nums[0] - nums[len - 1]);
        for (int i = 1; i < len; i++)
            ans = max(ans, abs(nums[i] - nums[i - 1]));
        return ans;
    }
};