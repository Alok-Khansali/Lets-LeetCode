class Solution //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
{
public:
    vector<vector<int>> ans;
    void get_my_ans(vector<int> nums , int i)  //There lies the sequence in the binary notation, where 1 means yes for a character to be present
    {                                          //And 0 means absent, following this pattern of 0s and 1s, all the subsets can be formulated
        int j = 0;
        vector<int>v;
        while(i)
        {
            if(i&1) 
                v.push_back(nums[j]);
            j++;
            i /= 2;
        }
        ans.push_back(v);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = pow(2,nums.size());
        for(int i = 0 ; i < n ;i++)
            get_my_ans(nums,i);
        return ans;
    }
};
/*//Bactracking
class Solution 
{
    public:
    vector<vector<int>> ans;
        void solve( vector<int>& nums, int cnt, vector<int> subset)
        {
            if(cnt == nums.size())   //traversed all elements
            {
                ans.push_back(subset);
                return;
            }
            solve(nums,cnt+1,subset);   //choice 1: don't push current element
            auto v = subset; 
            v.push_back(nums[cnt]);
            solve(nums,cnt+1,v);         //choice 2: push current element
        }
        vector<vector<int>> subsets(vector<int>& nums) 
        {
            solve(nums,0,{});
            return ans;
        }
};
*/