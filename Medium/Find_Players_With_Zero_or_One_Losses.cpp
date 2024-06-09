// Approach 1 : Using a map and sorting the keys
// Runtime: 883 ms, faster than 83.88 % of C++ online submissions for Find Players With Zero or One Losses.
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> mp;
        for (vector<int> v : matches)
        {
            int x = v[0], y = v[1];
            if (mp[x] >= 0)
                mp[x]++;
            else if (mp[y] >= 0)
                mp[y] = -1;
            else
                mp[y]--;
        }
        vector<vector<int>> v(2);
        for (auto x : mp)
            if (x.second > 0)
                v[0].push_back(x.first);
            else if (x.second == -1)
                v[1].push_back(x.first);
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());
        return v;
    }
};

// Approach 2 :  Building on the same approach, just using array as a map, memory efficient ofc
class Solution // Runtime: 393 ms, faster than 97.91% of C++ online submissions for Find Players With Zero or One Losses.
// Memory Usage: 146.9 MB, less than 98.85% of C++ online submissions for Find Players With Zero or One Losses.
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int mp[100006] = {0}, mx = INT_MIN;
        for (vector<int> v : matches)
        {
            int x = v[0], y = v[1];
            if (mp[x] >= 0)
                mp[x]++;
            if (mp[y] >= 0)
                mp[y] = -1;
            else
                mp[y]--;
            mx = max({mx, x, y});
        }
        vector<vector<int>> v(2);
        for (int i = 1; i <= mx; i++)
            if (mp[i] > 0)
                v[0].push_back(i);
            else if (mp[i] == -1)
                v[1].push_back(i);
        return v;
    }
};