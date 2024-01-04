class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &nums)
    {
        vector<long long> ans(nums.size(), 0);
        long long mx = nums[0];
        ans[0] = nums[0] * 2;
        for (int i = 1; i < nums.size(); i++)
        {
            mx = max((long long)nums[i], mx);
            ans[i] += ans[i - 1] + nums[i] + mx;
        }
        return ans;
    }
};