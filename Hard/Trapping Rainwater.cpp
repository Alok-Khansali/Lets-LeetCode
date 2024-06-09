// Approach 1, using left and right maximum
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(); // Number of elements in the input vector
        int water = 0;         // Variable to store the total trapped water

        // Arrays to store maximum height to the left and right of each index
        vector<int> l_max(n), r_max(n);

        // Calculate the maximum height to the left of each index
        l_max[0] = height[0]; // First element's maximum height to the left is itself
        for (int i = 1; i < n; i++)
            l_max[i] = max(height[i], l_max[i - 1]);

        // Calculate the maximum height to the right of each index
        r_max[n - 1] = height[n - 1]; // Last element's maximum height to the right is itself
        for (int i = n - 2; i >= 0; i--)
            r_max[i] = max(height[i], r_max[i + 1]);

        // Iterate through each index (excluding the first and last)
        for (int i = 1; i < n - 1; i++)
        {
            // Calculate the maximum water current height can hold above itself
            water += min(r_max[i], l_max[i]) - height[i];
        }
        return water; // Return the total trapped water
    }
};
// Approach 2 : Monotonic Stack
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(); // Number of elements in the height array
        int water = 0;         // Initialize the total trapped water volume
        vector<int> stack;     // Stack to store indices of height elements
        // Iterate through the heights
        for (int right = 0; right < n; right++)
        {
            // Process each height to trap water
            while (!stack.empty() && height[stack.back()] < height[right])
            {
                // If the current height is greater than the height at the top of the stack
                int mid = stack.back(); // Get the index of the height at the top of the stack
                stack.pop_back();       // Pop the index from the stack
                // If the stack becomes empty, no more water can be trapped
                if (stack.empty())
                    break;
                int left = stack.back();                                                      // Get the index of the next height from the top of the stack
                int minHeight = min(height[right] - height[mid], height[left] - height[mid]); // Calculate the minimum height of the two borders
                int width = right - left - 1;                                                 // Calculate the width between the left and right borders
                water += minHeight * width; // Calculate the trapped water volume and add it to the total
            }
            stack.push_back(right); // Push the current index onto the stack
        }
        return water; // Return the total trapped water volume
    }
};

// Approach 3 : One Pass, Two pointer
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;            // Initialize two pointers, one at the beginning and one at the end of the height vector
        int left_max = INT_MIN, right_max = INT_MIN; // Initialize variables to store the maximum height encountered so far from the left and right sides
        int water = 0;                               // Initialize a variable to store the total trapped water

        // Traverse the height vector from both ends towards each other until the pointers meet
        while (l < r)
        {
            left_max = max(left_max, height[l]);   // Update the maximum height encountered from the left side
            right_max = max(right_max, height[r]); // Update the maximum height encountered from the right side

            // Calculate the trapped water based on the lower maximum height encountered so far (between left_max and right_max)
            // If left_max is less than right_max, the current height at index l can trap water, otherwise, the current height at index r can trap water
            if (left_max < right_max)
                water += left_max - height[l++];
            else
                water += right_max - height[r--];
        }

        return water; // Return the total trapped water
    }
};