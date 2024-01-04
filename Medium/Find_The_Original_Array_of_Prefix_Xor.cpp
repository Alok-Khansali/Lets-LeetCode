class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int prev = 0;
        vector<int> ans;
        for (int i : pref)
        {
            int x = prev ^ i;
            ans.push_back(x);
            prev ^= x;
        }
        return ans;
    }
};