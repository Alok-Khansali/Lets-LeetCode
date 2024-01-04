// Approach 1 : Using Unordered_map, not valid as per follow up, time managed but not space
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        int l = nums.size();
        for (int i : nums)
            mp[i]++;
        for (auto i : mp)
            if (i.second > l / 3)
                ans.push_back(i.first);
        return ans;
    }
};

// Approach 2: Sorting and counting, space managed but not linear time
// Runtime: 12 ms, faster than 93.09% of C++ online submissions for Majority Element II.
// Memory Usage: 16 MB, less than 25.93% of C++ online submissions for Majority Element II.
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int c = 1, l = nums.size();
        // To bring the last element of the nums into checking
        nums.push_back(INT_MAX);
        vector<int> ans;
        for (int i = 0; i < l; i++)
        {
            while (nums[i] == nums[i + 1])
                c++, i++;
            if (c > l / 3)
                ans.push_back(nums[i]);
            c = 1;
        }
        return ans;
    }
};