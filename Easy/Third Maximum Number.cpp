class Solution {                                                      // This solution uses STL, Time Complexity = O(N * Log N), O(n) solution is at the bottom.
public:
   int thirdMax(vector<int>& nums) 
   {
       ios_base::sync_with_stdio(false);
	   cin.tie(NULL);
       
       sort(nums.begin() , nums.end() , greater<>());                   //    sorting in descending order
    
       nums.erase(unique(nums.begin() , nums.end()) , nums.end());      //Kepping only the distinct elements
       
       if(nums.size()>2)                                                // Checking if the array has at least 3 distinct elements
       {
           return nums[2];
       }
       return nums[0];                                                 // MAX Element returned, if the array has less than 3 elements
   }
};


/*                                    O(n) Solution, This one is slower than the above code as per leetcode's calcultaion
                                      Probably because it is using 3 if statements in the loop. If someone has a better answer please do tell me. 
                                      Thanks Already
class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
	      cin.tie(NULL);
        long f = LONG_MIN, s = LONG_MIN, t = LONG_MIN;            // Minimum Initialisation at values lesser than the constraints
        for(int i: nums)
        { 
            if(i>f)                                                // f = first, if i > first; pass down the values to s(second) and t(third)
            {
                t = s;
                s = f;
                f = i;
            }
            else if(i > s && i != f)                              // if(i > second such that i is not equal to f, which means  f > i > s
            {
                t = s;
                s = i;
            }
            else if(i > t && i != s && i != f)                    // if (f > s > i > t)  is satisfied modify t, where t is our third maximum
            {
                t = i;
            }
        }
        return ((t == LONG_MIN) ? f : t);                         // if third max == LONG_MIN, then this means our array has two or less distinct values
    }
};
*/
