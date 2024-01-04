class Solution
{
public:
    int ans = INT_MAX, avg = 0;
    void dp(int st, int n, vector<int> v, vector<int> &c, int k)
    {
        if (st == n)
        {
            int mx = std::max_element(v.begin(), v.end()) - v.begin(); // get the max element
            ans = min(ans, v[mx]);
            return;
        }
        for (int i = 0; i < k; i++)
        {
            if (i > 0 && v[i] == v[i - 1] || v[i] >= avg)   // Reducing the calls, 
                continue;
            v[i] += c[st];
            dp(st + 1, n, v, c, k);
            v[i] -= c[st];
        }
    }
    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> v(k, 0);
        avg = accumulate(cookies.begin(), cookies.end(), 0) / k;   // sum made easy
        dp(0, cookies.size(), v, cookies, k);
        return ans;
    }
};