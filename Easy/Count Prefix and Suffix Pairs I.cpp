class Solution // Fastest
{
public:
    bool pref(string a, string b)
    {
        int x = a.size(), y = b.size(), r = 0, z = 0;
        if (x > y)
            return false;
        while (r < x)
            if (b[z++] != a[r++])
                return false;
        while (--x >= 0)
            if (b[--y] != a[x])
                return false;
        return true;
    }
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int res = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                res += pref(words[i], words[j]);
        return res;
    }
};