class Solution
{
public:
    int partitionString(string s)
    {
        int n = s.size(), ans = 1;
        vector<int> v(26, 0);
        for (int i = 0; i < n; i++)
        {
            if (v[s[i] - 'a'])
            {
                v.clear();
                v.resize(26, 0);
                ans++;
            }
            v[s[i] - 'a']++;
        }
        return ans;
    }
};