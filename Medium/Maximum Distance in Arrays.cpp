class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int mx = arrays[0][arrays[0].size() - 1], mn = arrays[0][0];
        int ans = 0;
        for (int i = 1; i < arrays.size(); i++)
        {
            int len = arrays[i].size() - 1;
            ans = max(ans, abs(arrays[i][len] - mn));
            ans = max(ans, abs(mx - arrays[i][0]));
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i][len]);
        }
        return ans;
    }
};