class Solution { //Runtime: 200 ms, faster than 84.56% of C++ online submissions for 4Sum II.
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int ans = 0,l = nums1.size();
        unordered_map<int,int> f;
        for(int i =0;i<l;i++)
            for(int j = 0;j < l;j++)
                f[nums1[i]+nums2[j]]++;

        for(int i =0;i<l;i++)                                   //Improved Code Block
            for(int j = 0;j < l;j++)
                ans += f[-(nums3[i] + nums4[j])];
        return ans;
    }
};
/* First Thought Process
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int ans = 0,l = nums1.size();
        unordered_map<int,int> f,s;
        for(int i =0;i<l;i++)
        {
            for(int j = 0;j < l;j++)
            {
                f[nums1[i]+nums2[j]]++;
                s[nums3[i]+nums4[j]]++;
            }
        }
        for(auto i : f)
        {
          int x = 0 - i.first;
          if(s.find(x) != s.end())
              ans += (i.second * s[x]);
        }
        return ans;
    }
};//O(N^2) Solution
*/