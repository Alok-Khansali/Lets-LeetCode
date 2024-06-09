// First drafts are usually complicated
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int x = -1, y = -1, l = intervals.size();
        vector<vector<int>> ans;
        for (int i = 0; i < l; i++)
        {
            if ((newInterval[0] <= intervals[i][0] && newInterval[1] >= intervals[i][1]) || (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) || (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]))
            {
                x = min(newInterval[0], intervals[i][0]), y = max(newInterval[1], intervals[i][1]);
                i++;
                for (; i < l; i++)
                    if (intervals[i][0] <= y)
                        y = max(y, intervals[i][1]);
                    else
                    {
                        ans.push_back({x, y});
                        for (; i < l; i++)
                            ans.push_back(intervals[i]);
                        return ans;
                    }
            }
            else
                ans.push_back(intervals[i]);
        }
        if (x == -1)
            ans.push_back(newInterval);
        else
            ans.push_back({x, y});
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// To go simply
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else if (intervals[i][0] > newInterval[1])
            {
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            else if (intervals[i][1] >= newInterval[0] || intervals[i][0] >= newInterval[1])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};

// Similiar but in while
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size(), i = 0;
        vector<vector<int>> ans;
        while (i < n && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);
        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        ans.push_back(newInterval);
        while (i < n)
            ans.push_back(intervals[i++]);
        return ans;
    }
};