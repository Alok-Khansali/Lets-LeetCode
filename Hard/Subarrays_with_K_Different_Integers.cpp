class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int st = 0, len = nums.size(), ans = 0;
        for (int i = 0; i < len; i++)
        {
            mp[nums[i]]++;
            cout << mp.size() << ' ';
            if (mp.size() == k)
                ans++;
            while (st < len && mp.size() > k)
            {
                mp[nums[st]]--;
                if (mp[nums[st]] == 0)
                    mp.erase(nums[st]);
                st++;
                ans++;
            }
        }
        return ans;
    }
};