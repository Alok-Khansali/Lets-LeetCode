class Solution // 99.19 % faster
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> pref(len + 1), ans(len);
        for (int i = 0; i < len; i++)
            pref[i + 1] = pref[i] + nums[i];
        for (int i = 0; i < len; i++)
            ans[i] = pref[len] - pref[i + 1] - pref[i] + nums[i] * (2 * i + 1 - len);
        return ans;
    }
};