class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int a[1001] = {0}, l = nums.size();
        vector<int> ans;
        for (vector<int> v : nums)
        {
            for (int i : v)
                a[i]++;
        }
        for (int i = 0; i <= 1000; i++)
            if (a[i] == l)
                ans.push_back(i);
        return ans;
    }
};