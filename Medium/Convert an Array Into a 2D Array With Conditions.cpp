class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        int mx = 1;
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++, mx = max(mp[i], mx);
        vector<vector<int>> ans(mx);
        for (auto i : mp)
        {
            int x = i.first, y = mp[x];
            for (int i = 0; i < y; i++)
                ans[i].push_back(x);
        }
        return ans;
    }
};