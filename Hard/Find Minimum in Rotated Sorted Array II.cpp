class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        for(int i = 1;i< nums.size();i++)
        {
            if(nums[i-1] > nums[i])
            {
                return nums[i];
            }
        }
        return nums[0];
    }
};