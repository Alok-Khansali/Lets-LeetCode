class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        ios_base::sync_with_stdio(0);
        int ans = 0;
        unordered_map<string, int> mp;
        for (string s : words)
            if (s[0] == s[1])
            {
                mp[s]++;
                if (mp[s] == 2)
                {
                    ans += 4;
                    mp[s] = 0;
                }
            }
            else
            {
                string d = s;
                reverse(d.begin(), d.end());
                if (mp[d] > 0)
                    ans += 4, mp[d]--;
                else
                    mp[s]++;
            }
        for (auto x : mp)
            if (x.first[0] == x.first[1] && x.second > 0)
                return ans + 2;
        return (ans);
    }
};
// Try a way where you dont need to traverse the map again