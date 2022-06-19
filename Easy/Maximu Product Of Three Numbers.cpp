class Solution {  //Runtime: 45 ms, faster than 44.74 % of C++ online submissions for Maximum Product of Three Numbers.
public:
    int maximumProduct(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int first = INT_MIN, second = INT_MIN ,third = INT_MIN,lower = INT_MAX,lowest = INT_MAX;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]<lowest)
            {
                lower = lowest;
                lowest = nums[i];
            }
            else if(nums[i]<lower)
            {
                lower = nums[i];
            }
            if(nums[i] > first)
            {
                third = second;
                second = first;
                first = nums[i];
            }
            else if(nums[i]>second)
            {
                third = second;
                second = nums[i];
            }
            else if(nums[i]>third)
            {
                third = nums[i];
            }
        }
        return max(first * second * third, lowest * lower * first);
    }
};
/*
int maximumProduct(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int l = nums.size() - 1;
        sort(nums.begin(),nums.end());
        return max(nums[l]*nums[l-1]*nums[l-2],nums[0]*nums[1]*nums[l]);
    }
*/