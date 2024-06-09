class Solution
{
public:
    string makeGood(string s)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (i > 0 && abs(s[j] - s[i - 1]) == 32)
                i--;
            else
                s[i] = s[j], i++;
        }
        return s.substr(0, i);
    }
};