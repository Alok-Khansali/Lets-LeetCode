class Solution
{
public:
    int similarPairs(vector<string> &words)
    {
        map<vector<int>, int> mp;
        int ans = 0;
        for (string s : words)
        {
            vector<int> v(26, 0);
            for (char c : s)
                v[c - 'a'] = 1;
            ans += mp[v];
            mp[v]++;
        }
        return ans;
    }
};