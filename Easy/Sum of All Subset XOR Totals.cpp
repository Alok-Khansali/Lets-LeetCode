class Solution // No recursion
{
public:
    int subsetresSum(vector<int> &nums)
    {
        int len = nums.size(), ans = 0, x = 1;
        while (x != 1 << len)
        {
            int y = x, c = 0;
            for (int i = len - 1; i >= 0 && y > 0; i--)
            {
                if (y % 2)
                    c ^= nums[i];
                y /= 2;
            }
            ans += c;
            x += 1;
        }
        return ans;
    }
};
// recursion ofcource
class Solution
{
    int Chc(int i, vector<int> &nums, int res)
    {
        if (i == nums.size())
            return res;
        // take_it
        int take_it = Chc(i + 1, nums, nums[i] ^ res);
        // leave_it
        int leave_it = Chc(i + 1, nums, res);
        return take_it + leave_it;
    }

public:
    int subsetresSum(vector<int> &nums)
    {
        return Chc(0, nums, 0);
    }
};