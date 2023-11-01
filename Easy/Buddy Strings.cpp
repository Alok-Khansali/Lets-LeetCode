class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int l1 = s.size(), l2 = goal.size(), c = 0;
        if (l1 != l2 || l1 == 1)
            return false;
        unordered_map<char, int> mp, gp;
        for (int i = 0; i < l1; i++)
            mp[s[i]]++, gp[goal[i]]++, c += s[i] != goal[i];
        if (mp != gp || gp == mp && mp.size() == l1 && c != 2)
            return false;
        return (c == 2 || c == 0);
    }
};