// Using pairs
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        if (n == 1)
            return {"Gold Medal"};
        vector<vector<int>> v(n, vector<int>(2, 0));
        for (int i = 0; i < score.size(); i++)
            v[i][0] = score[i], v[i][1] = i;
        auto comp = [](const vector<int> &a, const vector<int> b)
        { return a[0] > b[0]; };
        sort(v.begin(), v.end(), comp);
        vector<string> s(n);
        if (n == 2)
        {
            s[v[0][1]] = "Gold Medal";
            s[v[1][1]] = "Silver Medal";
        }
        else
        {
            s[v[0][1]] = "Gold Medal";
            s[v[1][1]] = "Silver Medal";
            s[v[2][1]] = "Bronze Medal";
            for (int i = 3; i < n; i++)
                s[v[i][1]] = to_string(i + 1);
        }
        return s;
    }
};
// Approach 2 : Using map
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        ios_base::sync_with_stdio();
        int n = score.size();
        if (n == 1)
            return {"Gold Medal"};
        string a[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[score[i]] = i;
        sort(score.begin(), score.end(), greater<int>());
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i < 3)
                ans[mp[score[i]]] = a[i];
            else
                ans[mp[score[i]]] = to_string(i + 1);
        }
        return ans;
    }
};