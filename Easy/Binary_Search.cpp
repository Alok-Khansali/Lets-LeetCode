class Solution { //Runtime: 24 ms, faster than 99.63% of C++ online submissions for Binary Search.
                 //Memory Usage: 27.6 MB, less than 13.43% of C++ online submissions for Binary Search.
public:
    int search(vector<int>& nums, int target) 
    {
        
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int i=0,j=nums.size()-1;
        while(i <= j)
        {
            int m = i + (j-i)/2;
            if(nums[m] == target)
               return m;
            else if(nums[m]<target)
                i=m+1;
            else
                j=m-1;
        }
        return -1;
    }
};