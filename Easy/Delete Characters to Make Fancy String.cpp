// Nothing fancy, just the two pointers
class Solution
{
public:
    string makeFancyString(string s)
    {
        int len = s.size();
        if (len < 3)
            return s;
        int tw = 2;
        char fs = s[0], sd = s[1];
        for (int i = 2; i < len; i++)
        {
            if (fs == sd && sd == s[i])
                continue;
            s[tw++] = s[i];
            fs = sd, sd = s[i];
        }
        return s.substr(0, tw);
    }
};