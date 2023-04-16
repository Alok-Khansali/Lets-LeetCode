class Solution // 85.12% faster
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int l = reward1.size(), ans = 0;
        priority_queue<int> pq1;
        for (int i = 0; i < l; i++)
        {
            // The reward2 will be used completely
            ans += reward2[i];
            pq1.push(reward1[i] - reward2[i]);
        }
        while (k > 0)
        {
            k--;
            ans += pq1.top();
            pq1.pop();
        }
        return ans;
    }
};