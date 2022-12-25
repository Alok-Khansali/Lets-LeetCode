class Solution // Poor Implementation
// Runtime: 87 ms, faster than 9.77% of C++ online submissions for Relative Ranks.
// Memory Usage: 21.9 MB, less than 6.67% of C++ online submissions for Relative Ranks.
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        ios_base::sync_with_stdio(0);
        int n = score.size();
        if (n == 1)
            return {"Gold Medal"};
        vector<vector<int>> v(n, vector<int>(2, 0));
        for (int i = 0; i < score.size(); i++)
            v[i][0] = score[i], v[i][1] = i;
        auto comp = [](const vector<int> &a, const vector<int> b)
        {
            return a[0] > b[0];
        };
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

// Approach 2

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<pair<int, int>> vp;
        int n = score.size(), pos = 1;
        for (int i = 0; i < n; i++)
            vp.push_back({score[i], i});
        sort(vp.begin(), vp.end());
        vector<string> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                ans[vp[i].second] = "Gold Medal";
            else if (i == n - 2)
                ans[vp[i].second] = "Silver Medal";
            else if (i == n - 3)
                ans[vp[i].second] = "Bronze Medal";
            else
                ans[vp[i].second] = to_string(pos);
            pos++;
        }
        return ans;
    }
};