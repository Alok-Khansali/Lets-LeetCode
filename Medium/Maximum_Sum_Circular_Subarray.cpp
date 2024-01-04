class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        // better to calculate minimum sum array
        // Subtract it from the total sum of the array
        int mx_so_far = 0, mini = 0, sum = 0, mxm = nums[0], mnm = nums[0];
        for (int num : nums)
        {
            mx_so_far = max(mx_so_far, 0) + num, mxm = max(mxm, mx_so_far);
            mini = min(mini, 0) + num, mnm = min(mnm, mini), sum += num;
        }
        return ((sum == mnm) ? mxm : max(mxm, sum - mnm));
    }
};