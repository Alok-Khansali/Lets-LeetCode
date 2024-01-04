class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int len = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < nums[i].size(); j++)
                mp[i + j].push_back(nums[i][j]);
        vector<int> ans;
        for (auto i : mp)
        {
            vector<int> v = i.second;
            for (int i = v.size() - 1; i >= 0; i--)
                ans.push_back(v[i]);
        }
        return ans;
    }
};