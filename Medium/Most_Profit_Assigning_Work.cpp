class Solution
{
public:
    unordered_map<int, int> mp;
    int mx = 0, mxd = 0, ans = 0;
    int bin_ser(int i, vector<int> &d)
    {
        if (i >= mxd)
            return mx;
        if (mp[i] != 0)
            return mp[i];
        int x = lower_bound(d.begin(), d.end(), i) - d.begin();
        if (x == 0)
            return 0;
        return mp[d[x - 1]];
    }
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        for (int i = 0; i < profit.size(); i++)
            mp[difficulty[i]] = max(mp[difficulty[i]], profit[i]);
        sort(difficulty.begin(), difficulty.end());
        for (auto i : difficulty)
        {
            mx = max(mp[i], mx);
            mp[i] = mx;
            mxd = max(i, mxd);
        }
        for (int i : worker)
        {
            if (i >= mxd)
            {
                ans += mx;
                continue;
            }
            //cout << bin_ser(i, difficulty) << ' ';
            ans += bin_ser(i, difficulty);
        }
        return ans;
    }
};