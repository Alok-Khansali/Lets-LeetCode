class Solution //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Summary Ranges.
{
  public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;
        int x = nums.size(),j;
        for(int i = 0; i < x;i++)
        {
            j = i;
            while(i+1 < x && nums[i+1] == nums[i] + 1)
                i++;
            if(j == i)
                ans.push_back(to_string(nums[j]));
            else
                ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
        }
        return ans;
    }
};