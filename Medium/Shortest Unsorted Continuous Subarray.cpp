class Solution { //Runtime: 27 ms, faster than 93.72% of C++ online submissions for Shortest Unsorted Continuous Subarray.
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int mn = INT_MAX,mx = INT_MIN, l = nums.size(), x,y;
        for(int i = 1, f = 0;i < l;i++)
        {
            if(nums[i] < nums[i-1])
                f = 1;
            if(f)
                mn = min(mn,nums[i]);
        }
        for(int i = l - 2, f = 0;i >= 0;i--)
        {
            if(nums[i] > nums[i+1])
                f = 1;
            if(f)
                mx = max(mx,nums[i]);
        }
        for(x = 0;x < l;x++)
            if(mn < nums[x] )
                break;
        for(y = l-1;y >= 0;y--)
            if(nums[y] < mx)
                break;
        return max(0, y-x+1);
    }
};