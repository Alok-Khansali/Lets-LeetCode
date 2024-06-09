class Solution
{
public:
    int freq[100][26];
    vector<string> commonChars(vector<string> &words)
    {
        int len = words.size(), r = 0;
        memset(freq, 0, sizeof(freq));
        vector<string> res;
        for (string s : words)
        {
            for (char c : s)
                freq[r][c - 'a']++;
            r++;
        }
        for (int i = 0; i < 26; i++)
        {
            int mn = INT_MAX;
            for (int j = 0; j < len; j++)
                mn = min(freq[j][i], mn);
            for (int j = 0; j < mn; j++)
                res.push_back(string(1, 'a' + i));
        }
        return res;
    }
};
// Approach 2 : space optimised
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> max_frequency(26, INT_MAX);
        vector<string> res;
        for (const auto &w : words)
        {
            vector<int> char_count(26, 0);
            for (const auto &c : w)
                char_count[c - 'a']++;
            for (int i = 0; i < 26; i++)
                max_frequency[i] = min(max_frequency[i], char_count[i]);
        }
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < max_frequency[i]; j++)
                res.push_back(string(1, 'a' + i));
        return res;
    }
};