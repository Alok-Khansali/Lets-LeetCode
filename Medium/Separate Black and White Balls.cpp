class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        int maxi = 1, N = s.size();
        for (int fences = 0; fences < (1 << N - 1); ++fences)
        {
            if (__builtin_popcount(fences) < maxi)
                continue;
            unordered_set<string> S;
            string curr{s[0]};
            bool unique = true;
            for (int  bit = 0; bit < N - 1; ++bit)
            {
                if (fences >> bit & 1)
                {
                    if (!S.insert(curr).second)
                    {
                        unique = false;
                        break;
                    }
                    curr.clear();
                }
                curr.push_back(s[bit + 1]);
            }
            if (!S.insert(curr).second)
                continue;
            if (unique)
                maxi = max(maxi, S.size());
        }
        return maxi;
    }
};