class Solution // Approach 2
{
    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arithmetic Slices.
    // Memory Usage: 7.2 MB, less than 99.37% of C++ online submissions for Arithmetic Slices.
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0, t = 0;
        for (int i = 1; i < nums.size() - 1; i++)
            ans += (nums[i] - nums[i - 1] == nums[i + 1] - nums[i]) ? (t += 1) : (t = 0);
        return ans;
    }
};

// Approach 1, using a bit of math, but still above one is better
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int l = nums.size(), diff = 0, j = 0, ans = 0;
        if (l <= 2)
            return 0;
        diff = nums[1] - nums[0];
        for (int i = 2; i < l; i++)
        {
            while (i < l && nums[i] - nums[i - 1] == diff)
                i++;
            int x = i - j;
            if (x >= 3)
            {
                x -= 2;
                ans += (x * (x + 1)) / 2;
            }
            if (i >= l - 1)
                return ans;
            diff = nums[i] - nums[i - 1];
            j = i - 1;
            i -= 1;
        }
        return ans;
    }
};