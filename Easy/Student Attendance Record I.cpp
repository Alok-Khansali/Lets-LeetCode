class Solution
{
public:
    bool checkRecord(string s)
    {
        int a = 0, l = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'A')
            {
                if (a == 1)
                    return false;
                a = 1;
            }
            else if (s[i] == 'L')
            {
                while (i < s.size() && s[i] == 'L')
                    i++, l++;
                if (l > 2)
                    return false;
                l = 0, i -= 1;
            }
        return true;
    }
};