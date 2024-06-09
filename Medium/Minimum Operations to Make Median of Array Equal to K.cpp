class Solution //99.08% faster
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0);
        int len = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        if (nums[len / 2] == k)
            return 0;
        for (int i = len / 2 - 1; i >= 0; i--)
        {
            if (nums[i] > k)
                ans += nums[i] - k;
            else
                break;
        }
        for (int i = len / 2 + 1; i < len; i++)
        {
            if (nums[i] < k)
                ans += k - nums[i];
            else
                break;
        }
        ans += abs(k - nums[len / 2]);
        return ans;
    }
};