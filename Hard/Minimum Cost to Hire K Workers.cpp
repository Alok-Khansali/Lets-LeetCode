class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        vector<pair<double, int>> vp;
        int n = quality.size();
        double cost = numeric_limits<double>::max(), curr_quality = 0;
        // Wage to quality ratio
        for (int i = 0; i < n; i++)
        {
            vp.push_back({(double)(wage[i]) / (double)(quality[i]), quality[i]});
        }
        sort(vp.begin(), vp.end());
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            cout << "ratio : " << vp[i].first << '\n';
            pq.push(vp[i].second);
            curr_quality += vp[i].second;
            if (pq.size() > k)
            {
                curr_quality -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                cost = min(cost, curr_quality * vp[i].first);
        }
        return cost;
    }
};