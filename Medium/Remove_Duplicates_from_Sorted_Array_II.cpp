//Runtime: 4 ms, faster than 86.14% of C++ online submissions for Remove Duplicates from Sorted Array II.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int i=0,c=1;
        for (int j = 1 ; j < nums.size(); j++)    
        {
            if(nums[i] == nums[j] && c >= 2)
            {
                c++;
            }
            else if(nums[i] == nums[j])
            {
                nums[++i] = nums[j];
                c++;
            }
            else if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
                c=1;
            }
        }
        return i+1;
    }
};
/*
class Solution {      //Better Version
public:
    int removeDuplicates(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int i=0;
        for (int j = 0 ; j < nums.size(); j++)    
        {
            if(i<2 || nums[i-2] != nums[j])
            {
                nums[i++] =nums[j];
            }
        }
        return i;
    }
};
*/