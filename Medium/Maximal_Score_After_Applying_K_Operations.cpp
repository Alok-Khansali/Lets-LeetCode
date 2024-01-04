class Solution  //93.62% faster
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        long long ans = 0;
        for (int i : nums)
            pq.push(i);
        while (k--)
        {
            long long x = pq.top();
            ans += x;
            pq.pop();
            pq.push((x + 2) / 3); // Ceil function
        }
        return ans;
    }
};