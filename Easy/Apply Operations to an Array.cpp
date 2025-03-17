class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int len = nums.size(), st = 0;
        vector<int> ans(len, 0);
        for (int i = 1; i < len; i++)
        {
            if (nums[i] != 0 && nums[i - 1] == nums[i])
            {
                ans[st++] = nums[i] * 2;
                nums[i] = 0;
            }
            else if (nums[i - 1] != 0)
                ans[st++] = nums[i - 1];
        }
        if (nums[len - 1] != 0)
            ans[st] = nums[len - 1];
        return ans;
    }
};