// Slow code but this works
class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int len = words.size();
        vector<int> res(len, 0);
        vector<vector
        unordered_map<string, int> mp;
        for (string s : words)
        {
            string word = "";
            for (char c : s)
            {
                word += c;
                mp[word]++;
            }
        }
        for (int i = 0; i < len; i++)
        {
            string word = "";
            for (char c : words[i])
            {
                word += c;
                res[i] += mp[word];
            }
        }
        return res;
    }
};