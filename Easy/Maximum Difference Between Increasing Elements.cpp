class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int mn=INT_MAX,a=0;
        for(int i=0;i<nums.size();i++)
        {
                mn = min(nums[i],mn);
                a = max(nums[i]-mn,a);
        }
        return ((a!=0) ? a : -1);
    }
};
