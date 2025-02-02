// First approach best approach
// 94.13% better space
// 100% faster
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        ios_base::sync_with_stdio(0);
        int ans = 0, open = 0;
        for (char c : s)
            if (c == '(')
                open++;
            else if (open != 0)
                open--;
            else
                ans++;
        return ans + open;
    }
};