class Solution //Approach 1, just brute forced sorting
{ // Runtime: 87 ms, faster than 10.65% of C++ online submissions for Assign Cookies.
  // Memory Usage: 17.5 MB, less than 78.34% of C++ online submissions for Assign Cookies.
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, j = 0, k = 0;
        for (int i = 0; i < g.size(); i++)
        {
            while (k < s.size() && s[k] < g[i])
                k++;
            if (k < s.size())
            {
                if (s[k] >= g[i])
                    ans++;
                k++;
            }
            else
                break;
        }
        return ans;
    }
};