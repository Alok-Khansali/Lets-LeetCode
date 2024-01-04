class Solution // 100% better
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        char alt[26];
        for (int i = 0; i < 26; i++)
            alt[i] = (char)(i + 'a');
        for (int i = 0; i < s1.size(); i++)
        {
            char mx = max(alt[s1[i] - 'a'], alt[s2[i] - 'a']), mn = min(alt[s1[i] - 'a'], alt[s2[i] - 'a']);
            for (int i = 0; i < 26; i++)
                if (alt[i] == mx)
                    alt[i] = mn;
        }
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++)
            ans += alt[baseStr[i] - 'a'];
        return ans;
    }
};