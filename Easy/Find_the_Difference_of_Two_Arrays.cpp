class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> st1, st2;
        vector<vector<int>> ans(2);
        for(int i : nums1)
        st1.insert(i);
        for(int i : nums2)
        st2.insert(i);
        for(int i : nums1)
        {
            if(st2.find(i) == st2.end())
            {
                ans[0].push_back(i);
                st2.insert(i);
            }
        }
        for(int i : nums2)
        {
            if(st1.find(i) == st1.end())
            {
                ans[1].push_back(i);
                st1.insert(i);
            }
        }
        return ans;
    }
};