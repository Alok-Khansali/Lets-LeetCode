class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int len = nums.size(), res = nums[0];
        for (int i = 0; i < len; i++)
        {
            int curr = nums[i];
            while (i + 1 < len && nums[i] < nums[i + 1])
                curr += nums[++i];
            res = max(res, curr);
        }
        return res;
    }
};