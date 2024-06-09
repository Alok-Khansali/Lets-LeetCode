class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        unordered_map<string, int> mp;
        int parts = word.size() / k, max_freq = 0;
        for (int i = 0; i < word.size(); i += k)
        {
            string sub = word.substr(i, k);
            mp[sub]++;
        }
        for (auto i : mp)
        {
            if (i.second > max_freq)
                max_freq = max(max_freq, i.second);
        }
        return parts - max_freq;
    }
};