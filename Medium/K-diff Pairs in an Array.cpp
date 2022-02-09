class Solution { 
    //Runtime: 15 ms, faster than 87.88% of C++ online submissions for K-diff Pairs in an Array.
    //Memory Usage: 13.3 MB, less than 58.82% of C++ online submissions for K-diff Pairs in an Array.
public:
    int findPairs(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int ans = 0;
        unordered_map<int,int> st;
        for(int i : nums)
            st[i]++;
        if(k == 0)                          //I could have just used a set, had k been greater than 0
        {
            for(auto i : st)
               ans += (i.second > 1);
            return ans;
        }
        for(auto i : st)                   //I could have combined the two conditions 
        {
            int x = i.first + k;
            if(st.find(x) != st.end())
                ++ans;
        }
        return ans;
    }
};
/* //Like this
class Solution { //Runtime: 20 ms, faster than 73.03% of C++ online submissions for K-diff Pairs in an Array.
    //Memory Usage: 13.2 MB, less than 58.82% of C++ online submissions for K-diff Pairs in an Array.
public:
    int findPairs(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int ans = 0;
        unordered_map<int,int> st;
        for(int i : nums)
            st[i]++;
        for(auto i : st)
        {
            int x = i.first + k;
            if(k > 0 && st.find(x) != st.end() || k == 0 && i.second > 1)
                ++ans;
        }
        return ans;
    }
};
//Time Complexity O(N)
*/