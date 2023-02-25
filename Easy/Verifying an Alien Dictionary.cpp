class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int l = words.size();
        if (l == 1)
            return true;
        unordered_map<int, int> mp;
        for (int i = 0; i < order.size(); i++)
            mp[order[i]] = i;
        for (int i = 1; i < l; i++)
        {
            string s = words[i], w = words[i - 1];
            int x = min(s.size(), w.size());
            for (int j = 0; j < x; j++)
            {
                if (mp[w[j]] > mp[s[j]])
                    return false;
                if (mp[w[j]] < mp[s[j]])
                    break;
                if (j == x - 1 && s.size() < w.size())
                    return false;
            }
        }
        return true;
    }
};