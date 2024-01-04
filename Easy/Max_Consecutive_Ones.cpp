class Solution { //Runtime: 24 ms, faster than 98.22% of C++ online submissions for Max Consecutive Ones
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int j = 1, mx  = 0,l = nums.size();
        for(int i = 0;i < l;i++)
        {
            if(nums[i] == 1)
            {
                while(i<l-1 && nums[++i] == 1)
                {
                    ++j;
                }
                mx = max(j,mx);
                j = 1;
            }
        }
        return mx;
    }
};