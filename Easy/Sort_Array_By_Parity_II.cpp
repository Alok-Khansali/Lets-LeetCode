class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	     cin.tie(NULL);
       int i=0,j=nums.size()-1;
       while(i<nums.size() && j>0)
       {
           if(nums[i] % 2 == 0)
               i+=2;
           else if(nums[j] & 1)
               j-=2;
           else
           {
               swap(nums[i],nums[j]);
               i+=2;
               j-=2;
           }
       }
        return nums;
    }
};
