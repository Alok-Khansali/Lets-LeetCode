class Solution
{ // Runtime: 6 ms, faster than 98.29% of C++ online submissions for Minimum Moves to Equal Array Elements II.
    // Memory Usage: 10.9 MB, less than 15.75% of C++ online submissions for Minimum Moves to Equal Array Elements II.
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sort the game
        int x = nums.size(), ans = 0;
        int z = nums[x / 2]; // Get the element in the middle
        for (int i = 0; i < x; i++)
            ans += abs(nums[i] - z); // Add the absolute difference
        return ans;
    }
};