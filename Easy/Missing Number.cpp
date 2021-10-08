class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        
        int x = nums.size();
        x = (x*(x+1))/2;                //Sum of 1st n Natural numbers
        
        for(int i : nums)
        {
            x -= i;                      // Subtract all values from sum
        }
        return x;                        // Remaining element
    }
};