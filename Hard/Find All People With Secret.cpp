class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        unordered_set<int> st = {-1, 0, firstPerson};
        vector<int> ans = {0, firstPerson};
        for (vector<int> &v : meetings)
            if (v[0] == firstPerson)
                v[0] = -1;
            else if (v[1] == firstPerson)
                v[1] = -1;
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b)
             {
                    if (b[2] == a[2])
                    {
                        return (a[0] == -1 || a[1] == -1 || a[0] == 0 || a[1] == 0) >
                               (b[0] == -1 || b[1] == -1 || b[0] == 0 || b[1] == 0);
                    }
                    return a[2] < b[2]; });
        int i = 0, len = meetings.size();
        while (i < len && meetings[i][0] != -1 && meetings[i][1] != -1 && meetings[i][0] != 0 && meetings[i][1] != 0)
            i++;
        for (; i < len; i++)
        {
            int x = meetings[i][0], y = meetings[i][1];
            if (st.find(x) != st.end() || st.find(y) != st.end())
            {
                if (st.find(x) == st.end())
                {
                    ans.push_back(x);
                    st.insert(x);
                }
                else if (st.find(y) == st.end())
                {
                    ans.push_back(y);
                    st.insert(y);
                }
            }
        }
        return ans;
    }
};
// Approach 2
class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<pair<int, int>> graph[n];
        for (auto i : meetings)
        {
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<ppr, vector<ppr>, greater<ppr>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<int> vis(n, 0);
        while (!pq.empty())
        {
            int time = pq.top().first, person = pq.top().second;
            pq.pop();
            if (vis[person])
                continue;
            vis[person] = true;
            for (auto i : graph[person])
                if (!vis[i.first] && i.second >= time)
                    pq.push({i.second, i.first});
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (vis[i])
                ans.push_back(i);
        return ans;
    }
};