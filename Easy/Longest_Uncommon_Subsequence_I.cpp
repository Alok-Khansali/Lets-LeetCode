class Solution // 100% faster, 85.33% space efficient
{
public:
    int findLUSlength(string a, string b)
    {
        if (a != b)
            return max(a.size(), b.size());
        return -1;
    }
};