class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq;
        int ans = 0, x;
        for (int i : piles)
            pq.push(i);
        while (k--)
        {
            x = pq.top();
            pq.pop();
            x = (x + 1) / 2;
            pq.push(x);
        }
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};