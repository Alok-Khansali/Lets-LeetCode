class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int i = 0, l = profits.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < l; i++)
            vp.push_back({capital[i], profits[i]});
        sort(vp.begin(), vp.end());
        priority_queue<int> pq;
        for (int j = 0; j < k; j++)
        {
            while (i < l && vp[i].first <= w)
                pq.push(vp[i++].second);
            if (pq.empty())
                return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};