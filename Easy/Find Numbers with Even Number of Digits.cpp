class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int i : nums)
            ans += (i > 9 && i < 100) || (i > 999 && i < 10000) || i == 100000;
        return ans;
    }
};