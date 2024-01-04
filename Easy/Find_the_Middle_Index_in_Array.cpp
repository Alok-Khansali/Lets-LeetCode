class Solution {    //Runtime: 0 ms, faster than 100% of C++ online submissions for Find the Middle Index in Array.
public:
    int findMiddleIndex(vector<int>& nums) 
    {
        if(nums.size() == 1)
        {
            return 0;
        }
        int n = size(nums);
        vector<int> pre(n),suff(n);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
      
        for(int i = 1;i<n;i++)                   //Prefix Summation
            pre[i] = pre[i-1] + nums[i];
      
        for(int i = n-2;i>=0;i--)                //Suffix Summation
            suff[i] = suff[i+1] + nums[i];
      
        for(int i = 0;i<n;i++)
        {
            if(pre[i] == suff[i])
                return i;
        }
        return -1;
    }
};
