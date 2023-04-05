class Solution
{ // Runtime: 170 ms, faster than 73.40% of C++ online submissions for Minimum Average Difference.
  // Memory Usage: 79.1 MB, less than 53.19% of C++ online submissions for Minimum Average Difference.
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        long l = nums.size(), mn = INT_MAX, pos = 0, pf[l + 1];
        memset(pf, 0, sizeof(pf));
        for (int i = 1; i <= l; i++)
            pf[i] = pf[i - 1] + nums[i - 1];
        long sum = pf[l];
        for (int i = 1; i <= l; i++)
        {
            long x = pf[i] / i, y = sum - pf[i];
            y = (i == l) ? 0 : y / (l - i);
            // cout << x << ' ' << y << ' ' << i << '\n';
            if (abs(x - y) < mn)
                mn = abs(x - y), pos = i - 1;
        }
        return pos;
    }
};