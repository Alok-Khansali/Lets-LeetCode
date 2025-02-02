class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        ios_base::sync_with_stdio(0);
        int len = arr.size();
        vector<int> ans;
        for (int i = 1; i < len; ++i)
        {
            arr[i] ^= arr[i - 1];
        }

        for (vector<int> q : queries)
        {
            int res = arr[q[1]] ^ ((q[0] > 0) ? arr[q[0] - 1] : 0);
            ans.push_back(res);
        }
        return ans;
    }
};