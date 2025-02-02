// 99% faster
class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        ios_base::sync_with_stdio(0);
        int char_allowed[26] = {0}, consistent = 0;
        for (char c : allowed)
            char_allowed[c - 'a'] = 1;
        for (string s : words)
        {
            int passed = 1;
            for (char c : s)
            {
                if (char_allowed[c - 'a'] == 0)
                {
                    passed = 0;
                    break;
                }
            }
            consistent += passed;
        }
        return consistent;
    }
};