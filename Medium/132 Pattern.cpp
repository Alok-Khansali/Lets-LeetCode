//Stack Optimisation
class Solution { //Runtime: 62 ms, faster than 97.97% of C++ online submissions for 132 Pattern.
//Memory Usage: 37.5 MB, less than 98.98% of C++ online submissions for 132 Pattern.
public:
    bool find132pattern(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        if (nums.size() < 3)
            return false;
        stack<int> st;
        int f = INT_MIN;
        for(int i = nums.size() - 1;i >= 0;i--)
        {
            if(nums[i] < f)
                return true;
            while(!st.empty() && st.top() < nums[i])
            {
                f = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
/*  //101/102 cases passed
class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        if (nums.size() < 3)
            return false;
        bool f = 0;
        int mn = nums[0], mx = nums[0];
        vector<pair<int,int>> vp;
        
        for(int i = 1;i < nums.size(); i++)
        {
            if(f == 1)
            {
                for(auto z : vp)
                  if(nums[i] > z.first && nums[i] < z.second)
                     return true;
            }
            if(nums[i] < mn)
            {
               vp.push_back({mn,mx});
               f = 1;
               mn = nums[i], mx = mn;
            }
            else if(nums[i] > mx)
            {
                mx = nums[i];
            }
            else if(nums[i] > mn && nums[i] < mx)
                return true;
        }
        return false;
    }
};
*/