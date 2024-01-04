class Solution { //Runtime: 8 ms, faster than 41.52% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
                 //Memory Usage: 12.2 MB, less than 93.24% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
public:
    int findMin(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int i = 0, j= nums.size()-1;
        while(i < j)                   //Legendary Binary Search
        {
            int m = i + (j-i)/2;
            if(nums[m] < nums[j])      //This zone is sorted right and has no issues
                j = m;
            else if(nums[m] > nums[j]) // Welcome to the land of anomalies, smallest element lies in between (m,j]
                i = m+1;
            else                       //When The game is not as easy as it seems   eg ([1,3,3])
                --j; 
        }
        return nums[j];
    }
};
/*   Naive
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        for(int i = 1;i< nums.size();i++)
        {
            if(nums[i-1] > nums[i])
            {
                return nums[i];
            }
        }
        return nums[0];
    }
};
*/