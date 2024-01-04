class Solution
{
public:
    void char_check(vector<int> &m, string s)
    {
        for (char c : s)
            m[c - 'a']++;
    }
    bool test(vector<int> a, vector<int> b)
    {
        for (int i = 0; i < 26; i++)
            if (a[i] > b[i])
                return false;
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        vector<int> mst(26, 0);
        string ans(16, 'z');
        for (char c : licensePlate)
        {
            if (c >= 'a' && c <= 'z')
                mst[c - 'a']++;
            else if (c >= 'A' && c <= 'Z')
                mst[c - 'A']++;
        }
        for (string s : words)
        {
            vector<int> match(26, 0);
            char_check(match, s);
            if (test(mst, match) && s.size() < ans.size())
                ans = s;
        }
        return ans;
    }
};