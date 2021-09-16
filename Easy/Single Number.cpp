class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        for(int i=1;i<nums.size();i++)
            nums[0] ^= nums[i];
        return(nums[0]);
    }
};
