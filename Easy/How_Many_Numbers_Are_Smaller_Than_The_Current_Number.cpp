class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
             nums[i]=(lower_bound(v.begin(),v.end(),nums[i])-v.begin()) ;
       return(nums);
    }
};
