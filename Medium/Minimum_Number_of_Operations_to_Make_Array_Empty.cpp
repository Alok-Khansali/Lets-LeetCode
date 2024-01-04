// Approach 1 using Map
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> Table;
        for (int num : nums)
            Table[num]++;
        int ans = 0;
        for (auto num : Table)
        {
            int frequency = num.second;
            if (frequency == 1)
                return -1;
            ans += frequency / 3 + (frequency % 3 != 0);
        }
        return ans;
    }
};

// Approach 2 : Using sorting
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, index = 0, len = nums.size();
        while (index < len)
        {
            int frequency = 1;
            index++;
            for (; index < len && nums[index] == nums[index - 1]; index++, frequency++);
            if (frequency == 1)
                return -1;
            ans += frequency / 3 + (frequency % 3 != 0);
        }
        return ans;
    }
};