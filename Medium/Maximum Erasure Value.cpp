/*
O(N^2) is simple coz it will just require to loop one element
after the other, with new set, if any element repeats,
stop the loop, get the sum, if greater than the answer, set it as answer, else continue with the next element

*/

class Solution
{ // Runtime: 143 ms, faster than 99.76% of C++ online submissions for Maximum Erasure Value.
  // Memory Usage: 89.2 MB, less than 99.27% of C++ online submissions for Maximum Erasure Value.
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int a[10001] = {0};             // Creating a hashtable using the array, initialisng all the values to 0
                                        // Stating that No element has been traversed yet
        int prev = 0, sum = 0, ans = 0; // Using prev to store the index of the last deleted element
                                        // Sum to calculate the running sum, ans to store the sum of maximum unique subarray

        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i]; // Storing the current element in the vector nums, prevents the back to back access of elements

            if (a[x] != 0)               // If the hash value is not 0 for the element, that means it has occurred before
            {                            // Time to Decrease the available window
                int t = a[x];            // Store the previous index of this element
                while (prev < t)         // Subtract (from the sum) all the elements occurring in the vector from [prev, t), notice the brackets, 
                                         // indicating that element at prev is inclusive, but not the one at t is to be excluded
                    sum -= nums[prev++]; // The value of sum decreases, 
            }
            //Now Our Sliding window is of the size [i - prev + 1]
            a[x] = i + 1;        // Storing the occuring index of the current element
            sum += x;            // Aadding the value to the sum
            ans = max(ans, sum); // Storing the max sum in the answer variable
        }
        return ans;
    }
};