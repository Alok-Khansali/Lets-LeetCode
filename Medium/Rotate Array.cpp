class Solution {   //Runtime: 24 ms, faster than 93.45% of C++ online submissions for Rotate Array.
                   //Memory Usage: 24.9 MB, less than 92.88% of C++ online submissions for Rotate Array.
public:        //PURE STL
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
/*//Approach 1
class Solution {   //passes 37/38 cases
public:
    void rotate(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int len = nums.size(),r = 0;
        k %= len;
        for(int i = len-k; i < len; i++)
        {
            nums.insert(nums.begin() + r,nums[i+r]);
            r++;
        }
        nums.resize(len);
    }
};
//Approach 2
class Solution {   //Runtime: 57 ms, faster than 17.97% of C++ online submissions for Rotate Array.
                   //Memory Usage: 25.7 MB, less than 25.34% of C++ online submissions for Rotate Array.
public:
    void rotate(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        int len = nums.size(),r = 0,y=0;
        k %= len;
        for(int i = 0;i< len - k;i++)
            nums.push_back(nums[i]);
        for(int i = len-k; i < len; i++)
        {
            swap(nums[i],nums[r]);
            r++;  
        }
        for(;r < len;r++)
        {
            nums[r] = nums[len+y];
            y++;
        }
        nums.resize(len);
    }
};
*/