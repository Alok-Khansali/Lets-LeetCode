class Solution { //Runtime: 4 ms, faster than 81.27% of C++ online submissions for Maximum Product Subarray.
public:
    int maxProduct(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int maximum = nums[0], minimum = nums[0], answer = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] < 0)
            {
                swap(maximum,minimum);
            }
            minimum = min(minimum* nums[i],nums[i]);
            maximum = max(maximum* nums[i],nums[i]);
            answer = max(maximum,answer);
        }
        return answer;
    }
};
