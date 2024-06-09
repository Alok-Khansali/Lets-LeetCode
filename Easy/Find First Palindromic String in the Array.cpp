class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (string s : words)
        {
            int len = s.size(), c = 0;
            for (int j = 0; j < len / 2; j++)
                if (s[j] == s[len - j - 1])
                    c++;
                else
                    break;
            if (c == len / 2)
                return s;
        }
        return "";
    }
};