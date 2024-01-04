class Solution //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
{
  public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;
        int len = nums.size(),start_point;
        for(int end_point = 0; end_point < len;end_point++)
        {
            start_point = nums[end_point];
            while(end_point+1 < len && nums[end_point+1] == nums[end_point] + 1)
                end_point++;
            if(start_point == nums[end_point])
                ans.push_back(to_string(start_point));
            else
                ans.push_back(to_string(start_point) + "->" + to_string(nums[end_point]));
        }
        return ans;
    }
};