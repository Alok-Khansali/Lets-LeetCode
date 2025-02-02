class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int st = 0, ans = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - k <= nums[st] + k)
                ans = max(ans, i - st + 1);
            while (st < i && nums[st] + k < nums[i] - k)
                st++;
        }
        return ans;
    }
};