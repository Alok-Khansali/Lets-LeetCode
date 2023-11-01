// A solution that works great
// 2 - D dp.
/*
Idea here is simple
For every event there are two possibilities
Either take it or leave it
If you take it, reduce  k by 1:

Then use binary search to find the first event that takes place after [current's end time + 1]

Else :
Keep the K as it is, and raise the index to current + 1

Store dp[index][k] = max(take, leave)
*/
class Solution
{
public:
    vector<vector<int>> dp;
    vector<int> in_time;
    int doit(vector<vector<int>> &e, int k, int index, int length)
    {
        if (k == 0 || index >= length)
            return 0;
        if (dp[index][k] != -1)
            return dp[index][k];
        int next = lower_bound(in_time.begin(), in_time.end(), e[index][1] + 1) - in_time.begin();
        dp[index][k] = max(e[index][2] + doit(e, k - 1, next, length), doit(e, k, index + 1, length));
        return dp[index][k];
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        ios_base::sync_with_stdio(0);
        int length = events.size();
        dp.resize(length, vector<int>(k + 1, -1));
        sort(events.begin(), events.end());
        for (vector<int> v : events)
            in_time.push_back(v[0]);
        return doit(events, k, 0, length);
    }
};

// Approach 2: using a map to tabulate
// Reasoning being that not all the states of the dp will be accessed,
// So storing the states that are accessible
// This method is slightly better on space but it very slow
// Still better than 15.64 % cpp solution
class Solution
{
public:
    vector<int> in_time;
    map<pair<int, int>, int> dp;
    int doit(vector<vector<int>> &e, int k, int index, int l)
    {
        if (k == 0 || index >= l)
            return 0;
        if (dp.find({index, k}) != dp.end())
            return dp[{index, k}];
        int next = lower_bound(in_time.begin(), in_time.end(), e[index][1] + 1) - in_time.begin();
        int take = e[index][2] + doit(e, k - 1, next, l);
        int leave = doit(e, k, index + 1, l);
        dp[{index, k}] = max(take, leave);
        return dp[{index, k}];
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        int l = events.size();
        sort(events.begin(), events.end());
        for (vector<int> index : events)
            in_time.push_back(index[0]);
        return doit(events, k, 0, l);
    }
};