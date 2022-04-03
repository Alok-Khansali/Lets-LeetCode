class Solution { //Runtime: 60 ms, faster than 99.98% of C++ online submissions for Find the Duplicate Number.
                 //Memory Usage: 61.1 MB, less than 99.24% of C++ online submissions for Find the Duplicate Number.
public:
public:
    int findDuplicate(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int fst = nums[0], slw = nums[0];

        do
        {
            fst = nums[nums[fst]];
            slw = nums[slw];
        }while(fst != slw);

        slw = nums[0];
        
        while(slw != fst)
        {
            slw = nums[slw];
            fst = nums[fst];
        }
        return fst;
    }
};