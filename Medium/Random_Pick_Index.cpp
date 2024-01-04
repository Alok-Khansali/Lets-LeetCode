class Solution // improve on the timing of the code
// maybe work on the space too
{
public:
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> mr;
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
            mr[nums[i]]++;
        }
    }
    int pick(int target)
    {
        int x = mr[target] % mp[target].size();
        mr[target] = x + 1;
        return mp[target][x];
    }
};