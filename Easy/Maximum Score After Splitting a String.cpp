class Solution
{
public:
    int maxScore(string s)
    {
        int one = 0, zer = 0, res = 0, len = s.size();
        for (auto c : s)
        {
            one += c == '1';
        }
        for (int i = 0; i < len - 1; i++)
        {
            char c = s[i];
            zer += c == '0';
            one -= c == '1';
            res = max(res, zer + one);
        }
        return res;
    }
};