class Solution // 11ms Beats 99.83%of users with C++
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, l1 = g.size(), l2 = s.size(), i = 0, j = 0;
        while (i < l1 && j < l2)
        {
            if (g[i] <= s[j++])
                ans++, i++;
        }
        return ans;
    }
};