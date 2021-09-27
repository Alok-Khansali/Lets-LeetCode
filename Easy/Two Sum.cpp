class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v(2,0);
        for(int i=0;i<nums.size()-1;i++)
        {
            v[0]=i;
            for(int j=i+1;j<nums.size();j++)
                  if(nums[i]+nums[j]==target)
                  {
                      v[1]=j;
                      return(v);
                  }
        }
        return(v);
    }
};
