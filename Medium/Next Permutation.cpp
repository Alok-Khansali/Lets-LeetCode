class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
/* //Alternate method
class Solution {  //Runtime: 7 ms, faster than 51.84% of C++ online submissions for Next Permutation.
                  //Memory Usage: 12.2 MB, less than 37.25% of C++ online submissions for Next Permutation.
public:
    void nextPermutation(vector<int>& nums) 
    {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       int d = -1, len = nums.size();
       for(int i = len-1;i>0;i--)
       {
           if(nums[i] > nums[i-1])  //If the slope changes is positive
           {
               d = i - 1;           //Store the position and break
               break;
           }
       }
        if(d == -1)                 //Array in descending order
        {
            for(int i = 0;i < len/2;i++)
                swap(nums[i],nums[len - i - 1]);
            return;
        }
        
        //Find the lowest value greater than our value at index d+1
        int l = d+1;
        for(int i = l;i < len; i++)
        {
            if(nums[i] <= nums[d])
                break;
            l = (nums[i] <= nums[l] ? i : l);
        }  
        
        swap(nums[d],nums[l]);
        reverse(nums.begin() + d + 1, nums.end());
        return;
    }
};
*/