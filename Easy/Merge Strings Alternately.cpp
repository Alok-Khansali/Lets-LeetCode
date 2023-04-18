class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans = "";
        int i = word1.size(), j = word2.size(), a = 0, b = 0;
        while (a < i || b < j)
        {
            if (a < i)
                ans += word1[a++];
            if (b < j)
                ans += (word2[b++]);
        }
        return ans;
    }
};