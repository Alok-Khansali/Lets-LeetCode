class Solution
{
    // Runtime: 309 ms, faster than 52.95% of C++ online submissions for Contains Duplicate III.
    // Memory Usage: 80.6 MB, less than 15.80% of C++ online submissions for Contains Duplicate III.
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        ios_base::sync_with_stdio(0);
        vector<int> srt = nums;
        sort(srt.begin(), srt.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int j = lower_bound(srt.begin(), srt.end(), x - valueDiff) - srt.begin();
            int k = lower_bound(srt.begin(), srt.end(), x + valueDiff) - srt.begin();
            k -= (k == nums.size());
            for (; j <= k; j++)
                if (mp.find(srt[j]) != mp.end())
                    if (i - mp[srt[j]] <= indexDiff && abs(nums[i] - srt[j]) <= valueDiff)
                        return true;
            mp[x] = i;
        }
        return false;
    }
};