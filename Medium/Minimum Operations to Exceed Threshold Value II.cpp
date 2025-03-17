// Draft 1 : Bruteforce
// Passes for 674/675 test cases
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int ans = 0;
        for (int i : nums)
            if (i < k)
                pq.push(i);
        if (pq.size() == 1 && nums.size() > 1)
            return 1;
        while (pq.size() > 1)
        {
            if (pq.top() >= k)
                return ans;
            long long x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            ans++;
            x = x * 2 + y;
            pq.push(x);
        }
        return ans;
    }
};
// Draft 2 : Basic Simulation
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int ans = 0, mn2 = INT_MAX;
        for (int i : nums)
            if (i < k)
                pq.push(i);
            else
                mn2 = min(i, mn2);
        pq.push(mn2);
        while (pq.size() > 1)
        {
            if (pq.top() >= k)
                return ans;
            long long x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            ans++;
            x = x * 2 + y;
            pq.push(x);
        }
        return ans;
    }
};
// Draft 3 : Optimized Simulation
// 93.90% faster
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(),
                                                                            nums.end());
        int ans = 0;
        while (pq.top() < k)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            ans++;
            x = x * 2 + y;
            pq.push(x);
        }
        return ans;
    }
};