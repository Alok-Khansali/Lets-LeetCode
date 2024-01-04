class Solution {                     //Runtime: 8 ms, faster than 95.28% of C++ online submissions for Two Sum.
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        ios_base::sync_with_stdio(false);  
	    cin.tie(NULL);
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            if(m.find(target-nums[i])!=m.end())
            {
                return {i, m[target - nums[i]]};
            }
             else
                 m[nums[i]]=i;
        return {};
    }
};
