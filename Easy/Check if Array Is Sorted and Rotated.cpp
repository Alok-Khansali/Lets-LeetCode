class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int len = nums.size(), i = 1;
        while (i < len && nums[i] >= nums[i - 1])
            i++;
        if (i == len)
            return true;
        while (i + 1 < len && nums[i + 1] >= nums[i])
            i++;
        return i == len - 1 && nums[i] <= nums[0];
    }
};