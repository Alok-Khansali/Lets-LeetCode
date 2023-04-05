class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long long s = 0, mx = 0, r = 0;
        for (int i : nums)
        {
            s += i, r++;
            if (i != 1)
                mx = max(mx, (s + r - 1) / r);
        }
        return (int)mx;
    }
};