// First Draft: 2021-05-02
class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int len = nums.size(), zero = 0;
        int res = 1e6, st = 0, en = queries.size() - 1;
        // Check if nums is already all zeros
        for (int i : nums)
            zero += (i == 0);
        if (zero == len)
            return 0;
        while (st <= en)
        {
            vector<int> arr(len + 1, 0);
            int m = (st + en) / 2, pref = 0;
            bool valid = true;
            // Apply range updates
            for (int i = 0; i <= m; i++)
            {
                arr[queries[i][0]] += queries[i][2];
                arr[queries[i][1] + 1] -= queries[i][2];
            }
            // Compute prefix sum and validate
            for (int i = 0; i < len; i++)
            {
                pref += arr[i];
                if (pref < nums[i]) // Insufficient increase
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                res = min(res, m + 1);
                en = m - 1;
            }
            else
                st = m + 1;
        }
        return res == 1e6 ? -1 : res;
    }
};
// Time Complexity: O(N * log(N) + Q * log(N))
// Space Complexity: O(N)