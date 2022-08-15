class Solution // Runtime: 23 ms, faster than 39.99% of C++ online submissions for Roman to Integer.
// Memory Usage: 8.4 MB, less than 12.79% of C++ online submissions for Roman to Integer.
{
public:
    int romanToInt(string s)
    {
        ios_base::sync_with_stdio(0);
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int l = s.size(), a = m[s[l - 1]];
        for (int i = l - 2; i >= 0; i--)
        {
            if (m[s[i]] >= m[s[i + 1]])
                a += m[s[i]];
            else
                a -= m[s[i]];
        }
        return (a);
    }
};