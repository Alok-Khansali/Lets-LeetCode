// A solution that works but is way too slow
class Solution
{
public:
    int ans = 0;
    void dfs(int target, vector<int> &c, int i)
    {
        if (i == c.size() || target < 0)
            return;
        if (target == 0)
        {
            ans++;
            return;
        }
        dfs(target - c[i], c, i);
        dfs(target, c, i + 1);
    }
    int change(int amount, vector<int> &coins)
    {
        dfs(amount, coins, 0);
        return ans;
    }
};
// Dynamic programming
// For every amount just add the number of ways to make (current_amount - coins[i])
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        ios_base::sync_with_stdio(0);
        int st = 0;
        sort(coins.begin(), coins.end());
        int ways_to_do[5001] = {0};
        if (coins[0] == 1)
        {
            for (int i = 1; i <= amount; i++)
                ways_to_do[i] = 1;
            st = 1;
        }
        ways_to_do[0] = 1;
        for (int i = st; i < coins.size(); i++)
            for (int j = coins[i]; j <= amount; j++)
                ways_to_do[j] += ways_to_do[j - coins[i]];
        return ways_to_do[amount];
    }
};