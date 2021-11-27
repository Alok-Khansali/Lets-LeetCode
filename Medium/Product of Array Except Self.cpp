class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int lft = 1,rgt = 1,len = nums.size()-1;
        vector<int> res(len+1,1);
        for(int i = 0; i <= len; i++) 
        {
            res[i] *= lft;             //Left side continuous multiplication
            lft *= nums[i];			
            res[len - i] *= rgt;       //Right side continuous multiplication
            rgt *= nums[len - i];
        }
        return res;
    }
};
