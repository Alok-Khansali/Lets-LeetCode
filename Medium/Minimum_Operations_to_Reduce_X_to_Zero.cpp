// Approach 1
// TLE, for obvious reasons, Backtracking is not efficient, as it is 2^n, n being the size of the array
//
// Time Complexity of O(N^2)
class Solution
{
public:
    vector<vector<int>> ans;
    int op(vector<int> &nums, int x, int i, int j)
    {
        if (x <= 0)
            return x;
        if (i > j)
            return -1;
        if (ans[i][j] != -1) // If the pos is traversed, returned the value stored there
            return ans[i][j];
        int l = op(nums, x - nums[i], i + 1, j); // Otherwise, take an element from the left
        int r = op(nums, x - nums[j], i, j - 1); // Or take an element from the right
        if (l >= 0 && r >= 0)                    // if both greater than equal to 0, return the min of both
            ans[i][j] = 1 + min(l, r);
        else if (r >= 0) // If the right is greater than equal to 0, return 1 + right
            ans[i][j] = 1 + r;
        else if (l >= 0) // if the left is greater than equal to 0, return 1 + left
            ans[i][j] = 1 + l;
        return ans[i][j]; // return answer
    }
    int minOperations(vector<int> &nums, int x)
    {
        int l = nums.size();
        ans.resize(l, vector<int>(l, -1));
        return (op(nums, x, 0, l - 1));
    }
};

// Approach 2: Sliding Window
// The O(N) Game
class Solution
{
public:
    vector<vector<int>> ans;
    int minOperations(vector<int> &nums, int x)
    {
        int s = 0, cs = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
            s += nums[i];
        s -= x;
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            cs += nums[r];
            while (i <= j && cs > s)
                cs -= nums[i++];
            if (cs == s)
                ans = max(ans, j - i + 1);
        }

        return ((ans == -1) ? -1 : nums.size() - ans);
    }
};