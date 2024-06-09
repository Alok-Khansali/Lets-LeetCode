class Solution // First approach, bad Dp but solved it
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size(), mx = 1, pos = 0;
        vector<vector<int>> tr(n);
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
            tr[i].push_back(nums[i]);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1)
                {
                    dp[j] = dp[i] + 1;
                    tr[j] = tr[i];
                    tr[j].push_back(nums[j]);
                }
            }
            if (mx < tr[i].size())
            {
                mx = tr[i].size();
                pos = i;
            }
        }
        return tr[pos];
    }
};

class Solution // Second approach, good Dp, just building on the prev solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size(), mx = 1, pos = 0;
        vector<int> dp(n, 1), prev(n, -1), ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1)
                {
                    dp[j] = dp[i] + 1;
                    prev[j] = i;
                }
            }
            if (mx < dp[i])
            {
                mx = dp[i];
                pos = i;
            }
        }
        for (int i = pos; i != -1; i = prev[i])
            ans.push_back(nums[i]);
        return ans;
    }
};

class Solution // 99.97% faster coz array is always the fastest
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int mx = 1, pos = 0, n = nums.size(), dp[n], prev[n];
        memset(dp, 1, sizeof(dp));
        memset(prev, -1, sizeof(prev));
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] % nums[i] == 0 && dp[j] < dp[i] + 1)
                    dp[j] = dp[i] + 1, prev[j] = i;
            }
            if (mx < dp[i])
                mx = dp[i], pos = i;
        }
        for (int i = pos; i != -1; i = prev[i])
            ans.push_back(nums[i]);
        return ans;
    }
};