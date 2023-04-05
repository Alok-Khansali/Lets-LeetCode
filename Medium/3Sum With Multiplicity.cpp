class Solution { //Runtime: 1090 ms, faster than 24.83% of C++ online submissions for 3Sum With Multiplicity.
//Memory Usage: 10.9 MB, less than 20.41% of C++ online submissions for 3Sum With Multiplicity.
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int m = 1e9 + 7, ans = 0, len = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0;i < len;i++)
        {
            ans = (ans + mp[target - arr[i]])% m;
            for(int j = 0; j < i ; j++)
            {
                mp[arr[i] + arr[j]]++;
            }
        }
        return ans;
    }
};