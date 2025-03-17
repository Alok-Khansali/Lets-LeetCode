class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
            sum += n % 10, n /= 10;
        return sum;
    }
    int maximumSum(vector<int> &nums)
    {
        int ans = -1;
        unordered_map<int, pair<int, int>> mp;
        for (int i : nums)
        {
            int dig = getSum(i);
            if (mp.find(dig) == mp.end())
                mp[dig] = {i, 0};
            else
            {
                auto x = mp[dig];
                int a = x.first, b = x.second;
                if (a < i)
                    mp[dig] = {i, a};
                else
                    mp[dig] = {a, max(i, b)};
            }
        }
        for (auto i : mp)
            if (i.second.second != 0)
                ans = max(ans, i.second.first + i.second.second);
        return ans;
    }
};