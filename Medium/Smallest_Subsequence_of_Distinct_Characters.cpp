class Solution // 100% faster, 91.80% more space efficient
{
public:
    string smallestSubsequence(string s)
    {
        string ans = "";
        int frq[26] = {0}, vis[26] = {0};
        for (int i = 0; i < s.size(); i++)
            frq[s[i] - 'a']++;
        for (int i = 0; i < s.size(); i++)
        {
            if (vis[s[i] - 'a'])
            {
                frq[s[i] - 'a']--;
                continue;
            }
            while (!ans.empty() && ans.back() > s[i] && frq[ans.back() - 'a'] > 1)
            {
                frq[ans.back() - 'a']--;
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        return ans;
    }
};

