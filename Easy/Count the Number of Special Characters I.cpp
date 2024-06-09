class Solution // 100% faster, 80% better space
{
public:
    int numberOfSpecialChars(string word)
    {
        int lower[26] = {0}, upper[26] = {0}, ans = 0;
        for (char c : word)
            if (c >= 'a' && c <= 'z')
                lower[c - 'a']++;
            else
                upper[c - 'A']++;
        for (int i = 0; i < 26; i++)
            ans += (lower[i] > 0 && upper[i] > 0);
        return ans;
    }
};