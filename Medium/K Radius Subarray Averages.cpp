class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        long long len = nums.size(), total = 2 * k + 1, sum = 0;
        vector<int> ans(len, -1);
        if (total > len)
            return ans;
        for (int i = 0; i < total - 1; i++)
            sum += nums[i];
        for (int i = k; i < len - k; i++)
        {
            sum += nums[i + k];
            // cout << sum << ' ';
            ans[i] = sum / total;
            sum -= nums[i - k];
        }
        return ans;
    }
};