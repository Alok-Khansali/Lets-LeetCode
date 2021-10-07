class Solution {
public:
    int binsearch(vector<int>& n,int l,int r,int t)
    {
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(n[m] == t)
                return m;
            else if( n[m] < t)
                l = m+1;
            else
                r = m - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) 
    {
        int pos=0,l=nums.size();
        for(int i=1; i < l; i++)
            if(nums[i] < nums[i-1])
                pos = i;
        if(target <= nums[l-1])
           return binsearch(nums, pos, l-1, target);
        return binsearch(nums, 0, pos-1, target);
    }
};