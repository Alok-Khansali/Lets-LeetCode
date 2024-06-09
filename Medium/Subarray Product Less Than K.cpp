#include <vector>

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int n = nums.size(), product = 1, start = 0, count = 0;
        for (int end = 0; end < n; end++)
        {
            product *= nums[end];
            while (start <= end && product >= k)
                product /= nums[start++];
            count += end - start + 1;
        }
        return count;
    }
};
