/*
//Approach 1
//Easiest way but not alllowed as per the constraints
class Solution {  //Runtime: 149 ms, faster than 77.44% of C++ online submissions for Longest Consecutive Sequence.
                  //Memory Usage: 33.7 MB, less than 91.70% of C++ online submissions for Longest Consecutive Sequence.
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(),nums.end());            //Sort
        int ans = 0, c = 1;
        for(int i = 1; i < nums.size();i++)
        {
            if(nums[i] == nums[i-1])              //if same go ahead
                continue;
            if(nums[i] == (nums[i-1] + 1))        //if consec inc the counter
                c++;
            else
            {
                ans = max(ans, c);                // else get the max length
                c = 1;                            // reset the counter
            }
        }
        return max(ans,c);                        // return the max length
    }
};
*/



//O(N) Approach
//Using set 
class Solution {  
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans = 0, c = 0;
        unordered_set<int> st;
        //Get the single occurances
        for(int i : nums)
            st.insert(i);
        for(int i : st)
        {
            //If no element 1 less than the current element is found
            //Apply the following logic
            if(st.find(i-1) == st.end())
            {
                c = 1;
                //Store the current starting point
                int x = i;
                //Until there exists a consecutive sequence 
                //Keep searching
                //Keep increasing the current streak
                while(st.find(x+1) != st.end())
                    c += 1 ,  x += 1;
                //Get the maximum of all streaks
                ans = max(ans, c);
            }
        }
        //Return the longest streak
        return ans;
    }
};