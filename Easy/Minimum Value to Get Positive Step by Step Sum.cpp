class Solution {                         //Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Value to Get Positive Step by Step Sum.
public:
    int minStartValue(vector<int>& nums) 
    {
        int minimum = min(0,nums[0]);           //minimum can either be 0 or a negative value
        for(int i = 1;i<nums.size();i++)
        {
            nums[i] +=nums[i-1];                //Prefix summation
            minimum = min(minimum,nums[i]);     //Getting the minimum value of prefix summation
        }
        return (-minimum + 1);                  //Minimum will be absolute value of (minimum +1)
    }
};
