class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        long long len = nums.size(), mx = -1, prev = 0;
        for (int i = 0; i < len; i++)
        {
            if (i >= 2 && nums[i] < prev)
                mx = nums[i] + prev;
            prev += nums[i];
        }
        return mx;
    }
};