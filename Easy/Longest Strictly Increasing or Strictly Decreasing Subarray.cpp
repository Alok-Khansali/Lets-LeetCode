class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int len = 1, curr = 1, sz = nums.size();
        for (int i = 0; i < sz - 1;)
        {
            // Upward slope
            while (i + 1 < sz && nums[i] < nums[i + 1])
                i++, curr++;
            len = max(len, curr), curr = 1;
            // Downward slope
            while (i + 1 < sz && nums[i] > nums[i + 1])
                i++, curr++;
            len = max(len, curr), curr = 1;
            // Flat land
            while (i + 1 < sz && nums[i] == nums[i + 1])
                i++;
        }
        return len;
    }
};