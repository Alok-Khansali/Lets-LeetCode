class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        unordered_set<int> st;
        int mx = -1, c = 0, ans = 0;
        for (int i : divisors)
        {
            c = 0;
            if (st.find(i) == st.end())
                for (int j : nums)
                    c += (j % i == 0);
            if (c > mx)
                mx = c, ans = i;
            else if (c == mx)
                if (i < ans)
                    ans = i;
            // cout << mx << ' ' << ans << '\n';
            st.insert(i);
        }
        return ans;
    }
};