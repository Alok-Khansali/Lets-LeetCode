class Solution {   //0 ms, faster than 100.00% of C++ online submissions for Single Element in a Sorted Array.
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int l = 0, h = nums.size()-2; 
        while(l <= h)
        {
            int m = l + (h-l)/2;
            if(nums[m] == nums[m^1])
            {
                l = m+1;
            }
            else 
            {
                h = m-1;
            }
        }
        return nums[l];
    }
};
