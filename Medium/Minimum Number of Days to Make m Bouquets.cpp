class Solution
{
public:
    int minDays(vector<int> nums, int m, int k)
    {
        ios_base::sync_with_stdio(0);
        long long int n = nums.size(), left = 1, right = 1000000001, total = m;
        if (total * k > n)
            return -1;
        while (left < right)
        {
            int mid = (left + right) / 2, flower = 0, bouquet = 0;
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] > mid)
                    flower = 0;
                else if (++flower >= k)
                {
                    bouquet++;
                    flower = 0;
                }
            }
            if (bouquet < m)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};