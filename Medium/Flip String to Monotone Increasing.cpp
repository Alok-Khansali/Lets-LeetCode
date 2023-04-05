class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int ans = 0, one = 0;
        for (char c : s)
            if (c == '0')
                ans = min(one, ans + 1);
            else
                ++one;
        return ans;
    }
};