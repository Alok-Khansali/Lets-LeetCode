class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int res = 0, prev = 0;
        for (string s : bank)
        {
            int ans = 0;
            for (char c : s)
                ans += c == '1';
            if (ans == 0)
                continue;
            res += prev * ans, prev = ans;
        }
        return res;
    }
};