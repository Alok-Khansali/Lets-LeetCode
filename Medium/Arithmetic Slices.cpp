class Solution 
{ 
    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arithmetic Slices.
    // Memory Usage: 7.2 MB, less than 99.37% of C++ online submissions for Arithmetic Slices.
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int ans = 0, t  = 0;
        for (int i = 1; i < nums.size()-1; i++)
		   ans += (nums[i] - nums[i - 1] == nums[i + 1] - nums[i]) ? (t += 1) : (t = 0);
        return ans;
    }
};