class Solution {                                  //Runtime: 32 ms, faster than 99.73% of C++ online submissions for Find All Numbers Disappeared in an Array.
public:                                           //O(n) Solution
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)      //Negation Technique
        {
            int index = abs(nums[i])-1;                      
            nums[index] = abs(nums[index]) * (-1);  //Substitute the value at (nums[i] - 1) with the negated value of the absolute value at that index
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)                        //If index is positive, that means (index + 1) element is not present in the array 
            {
                answer.push_back(i+1);              //We can simply push (index + 1) into the array;
            }
        }
        return answer;
    }
};
/*
class Solution {            //Sorting implementation, O(nlog(n)) time
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        vector<int> v;
        sort(nums.begin(),nums.end());
        int r=1,l = nums.size();
        while(nums[0]-r > 0)
        {
            v.push_back(r);
            r++;
        }
        for(int i = 1;i<l;i++)
        {
                while(nums[i]-nums[i-1]>1)
                { 
                    ++nums[i-1];
                    v.push_back(nums[i-1]);
                }
        }
        while(l - nums[l-1] > 0)
        {
            ++nums[l-1];
            v.push_back(nums[l-1]);
        }
        return v;
    }
};
*/
