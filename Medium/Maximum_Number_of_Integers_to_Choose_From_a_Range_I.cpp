class Solution //Brute force with set and 63% faster
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_set<int> st;
        for (int i : banned)
            st.insert(i);
        int z = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (st.find(i) != st.end())
                continue;
            z += i;
            if (z <= maxSum)
                ans++;
            else
                return ans;
        }
        return ans;
    }
};