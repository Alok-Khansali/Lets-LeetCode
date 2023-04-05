class Solution
{
public:
    vector<vector<int>> ans;
    void cmb(vector<int> v, int n, int k, int j)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = j + 1; i <= n; i++)
        {
            v.push_back(i);
            cmb(v, n, k, i);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        ios_base::sync_with_stdio(0);
        cmb({}, n, k, 0);
        return ans;
    }
};