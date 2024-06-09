class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        ios_base::sync_with_stdio(0);
        int len = s.size(), one = 0;
        string ans = "";
        for (char c : s)
            one += c == '1';
        for (int i = 0; i < one - 1; i++)
            ans += "1";
        for (int i = 0; i < len - one; i++)
            ans += "0";
        return ans + "1";
    }
};