class Solution { //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array II.
                 //Memory Usage: 14 MB, less than 71.85% of C++ online submissions for Search in Rotated Sorted Array II.
public:
    bool search(vector<int>& nums, int target) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        for(int i : nums)
        {
            if(i == target)
                return true;
        }
        return false;
    }
};