class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int len = nums.size(), pos = 0, neg = 0;
        if (nums[0] > 0 || nums[len - 1] < 0)
            return len;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] < 0)
                neg++;
            else if (nums[i] > 0)
                pos++;
        }
        return max(pos, neg);
    }
};