// Traditional Recursive-Backtracking solution
class Solution
{
public:
    vector<vector<int>> permutations;
    void solve(int i, vector<int> &nums)
    {
        if (i == nums.size())
        {
            permutations.push_back(nums);
            return;
        }
        for (int j = i; j < n; j++)
        {
            swap(nums[i], nums[j]);
            solve(i + 1, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        solve(0, nums);
        return permutations;
    }
};

// Stylish STL solution
// 100% faster
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &a)
    {
        ios_base::sync_with_stdio(0);
        sort(a.begin(), a.end());
        vector<vector<int>> v(1, a);
        while (next_permutation(a.begin(), a.end()))
            v.push_back(a);
        return (v);
    }
};
