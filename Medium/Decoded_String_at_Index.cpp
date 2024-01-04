class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        vector<pair<string, long long int>> vp;
        string w;
        long long int track = 0, len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                w += s[i];
            else
            {
                string num = "";
                while (i < len && s[i] >= '0' && s[i] <= '9')
                    num += s[i];
                long long int x = w.size(), mul = stoll(num);
                if (track + x * mul >= k)
                {
                    k -= track;
                    k %= x;
                    k = (k == 0) ? x : k - 1;
                    return w[k];
                }
                track += x * mul;
                w = "";
            }
        }
        return 'a';
    }
};