class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i] == s[j])
            {
                while (i < j && s[i] == s[++i])
                    i++;
                while (i < j && s[j] == s[--j])
                    j--;
                j--, i++;
            }
            else
                return j - i + 1;
        return max(0, j - i + 1);
    }
};