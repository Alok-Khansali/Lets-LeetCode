class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int r=0,w=0,b=0,i=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
                r++;
            else if(nums[i]==1)
                w++;
            else
                b++;
        for(i=0;i<r;i++)
            nums[i]=0;
        for(;i<r+w;i++)
            nums[i]=1;
        for(;i<nums.size();i++)
            nums[i]=2;
    }
};
