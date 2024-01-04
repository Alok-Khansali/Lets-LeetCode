class Solution {                       //Runtime: 16 ms, faster than 98.99% of C++ online submissions for Non-decreasing Array.
public:
    bool checkPossibility(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int c=0;                                                         //Flag variable => tracks anomalies
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])                                        //If the preceding element is greater increment flag
            {
                ++c;
                if(c > 1)                                                 //If the array has more than one flag is found return false
                {
                    return false;
                }
                if(i > 1 && nums[i]<nums[i-2])             //If length is more than 2 and the ith element is also less than (i-2)th element change ith element to (i-1)th element.
                {                                          //This is the only change that can be made
                  nums[i] = nums[i-1];
                }
            }
        }
        return true;                                       //Return true if at most we have one anomaly
    }
};
