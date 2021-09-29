class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        cout.tie(NULL);
        int i=0,j=nums.size()-1,c=0;
        while(i<=j)
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
