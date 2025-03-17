class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int ans = 0, len = nums.size();
        map<int, int> mp;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                mp[nums[i] * nums[j]]++;
        for (auto i : mp)
        {
            int val = i.second;
            ans += 4 * (val * (val - 1));
            // basically 8 * ((val * (val - 1)) / 2)
            // 8 *(n * (n-1)/2);
            // n * (n-1)/2 these many combinations exists
        }
        return ans;
    }
};