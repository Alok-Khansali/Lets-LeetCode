// Approach 1 : Simple bruteforce
// 100 % faster
class Solution
{
public:
    int minChanges(string s)
    {
        char c = s[0];
        int ct = 1, ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == c)
                ct++;
            else
            {
                ans += ct & 1;
                ct = 1 + (ct & 1);
                c = s[i];
            }
        }
        return ans;
    }
};