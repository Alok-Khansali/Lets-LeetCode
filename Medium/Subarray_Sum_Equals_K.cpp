class Solution  //Runtime: 84 ms, faster than 75.47% of C++ online submissions for Subarray Sum Equals K.
{
  public:
    int subarraySum(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        unordered_map<int,int> mp;
        mp[0] = 1;
        int s = 0, ans = 0;
        for(int i : nums)
        {
            s += i;
            if(mp.find(s - k) != mp.end())
            {
                ans += mp[s-k];
            }
            mp[s]++;
        }
        return ans;
    }
};