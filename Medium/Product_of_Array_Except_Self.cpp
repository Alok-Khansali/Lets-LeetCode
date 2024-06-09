class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int lft = 1, rgt = 1, len = nums.size() - 1;
        vector<int> res(len + 1, 1);
        for (int i = 0; i <= len; i++)
        {
            res[i] *= lft; // Left side continuous multiplication
            lft *= nums[i];
            res[len - i] *= rgt; // Right side continuous multiplication
            rgt *= nums[len - i];
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prod1 = 1, prod2 = 1, zero = 0, n = nums.size();
        for (int i : nums)
        {
            zero += (i == 0);
            if (i != 0)
                prod1 *= i;
        }
        vector<int> ans(n, 0);
        if (zero > 1)
            return ans;
        prod2 = ((zero == 0) ? prod1 : 0);
        // cout << '\n' << prod1 << ' ' << prod2 << ' ' << zero << '\n';
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                ans[i] = prod1;
            else
                ans[i] = prod2 / nums[i];
        }
        return ans;
    }
};
