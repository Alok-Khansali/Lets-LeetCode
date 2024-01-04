class Solution // Draft 1, when i thought i needed all indices of a number
// Runtime: 458 ms, faster than 21.82% of C++ online submissions for Contains Duplicate II.
// Memory Usage: 97.3 MB, less than 7.44% of C++ online submissions for Contains Duplicate II.
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (mp.find(x) != mp.end())
                for (int n : mp[x])
                    if (i - n <= k)
                        return true;
            mp[x].push_back(i);
        }
        return false;
    }
};
// Draft 2, when i realised i only needed the last index of the number
// Decreased the time and space considerably
class Solution
{ // Runtime: 248 ms, faster than 79.07% of C++ online submissions for Contains Duplicate II.
  // Memory Usage: 77.2 MB, less than 33.65% of C++ online submissions for Contains Duplicate II.
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (mp.find(x) != mp.end())
                if (i - mp[x] <= k)
                    return true;
            mp[x] = i;
        }
        return false;
    }
};