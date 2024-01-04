class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        map<int,int> m;
        int s=0;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto x: m)
              s += (x.second*(x.second-1))/2;
        return(s);
    }
};
